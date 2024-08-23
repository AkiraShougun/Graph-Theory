#ifdef GL_ES
precision mediump float;
#endif



uniform vec2 u_resolution;

void main() {
    vec2 c =  ((gl_FragCoord.xy * 2.0 - u_resolution.xy) / u_resolution.y) ;
    vec2 z = vec2(0.0, 0.0);
    int max_iterations = 100;
    int iterations = 0;

    for (int i = 0; i < 100; i++) {
        if (dot(z, z) >= 4.0) break;
        z = vec2(
            z.x * z.x - z.y * z.y + c.x,
            2.0 * z.x * z.y + c.y
        );
        iterations++;
    }

    float color = float(iterations) / float(max_iterations);
    gl_FragColor = vec4(vec3(color), 1.);
}
