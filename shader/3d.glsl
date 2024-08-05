#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution; 

const float r = 0.5; // Radius
const int numSteps = 100; // Number of steps for approximation

float cycloidSDF(vec2 p) {
    float minDist = 1e20; // Start with a large number
    float step = 6.28318530718 / float(numSteps); // 2 * PI divided by number of steps
    for (int i = 0; i < numSteps; i++) {
        float t = float(i) * step;
        // Parametric equations for the cycloid
        float x = r * (t - sin(t));
        float y = r * (1.0 - cos(t));
        // Distance from point p to the current point on the cycloid
        float dist = length(p - vec2(x, y));
        // Update minimum distance
        minDist = min(minDist, dist);
    }
    return minDist;
}

void main(){
    vec2 uv = gl_FragCoord.xy / u_resolution.xy;
    vec2 p = uv * 5.0 - 1.0;
    float dis = cycloidSDF(p);
    float d = smoothstep(0.01,0.4,dis);
    d = 0.03/d;
    vec3 color = vec3(d);

    gl_FragColor = vec4(color,1.0);
}