#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;  // Resolution of the canvas
uniform float u_time;


float ndot(vec2 a, vec2 b ) { return a.x*b.x - a.y*b.y; }
float sdRhombus( vec2 p, vec2 b ) 
{
    p = abs(p);
    float h = clamp( ndot(b-2.0*p,b)/dot(b,b), -1.0, 1.0 );
    float d = length( p-0.5*b*vec2(1.0-h,1.0+h) );
    return d * sign( p.x*b.y + p.y*b.x - b.x*b.y );
}

mat2 rotate(float angle){
    return mat2(vec2(cos(angle),-sin(angle)),vec2(sin(angle),cos(angle)));
}

void main() {
    // Normalize the pixel coordinates to the range [-1, 1]...
    vec2 uv = ((gl_FragCoord.xy * 2.0 - u_resolution.xy) / u_resolution.y) ;
    uv = rotate(u_time)*uv;
    float d = sdRhombus(uv,vec2(0.3,0.3));
    vec3 color = vec3(0.2118, 0.7412, 0.8314);
    d=abs(d);
    // Determine the color of the pixel
    d=0.1/d;

    color *= d;

    // Set the fragment color...
    gl_FragColor = vec4(color, 1);
}