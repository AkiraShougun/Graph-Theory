#ifdef GL_ES
precision highp float;
#endif

// Enable the standard derivatives extension
#extension GL_OES_standard_derivatives : enable

uniform float time;
uniform vec2 resolution;

void main() {
    // Normalize pixel coordinates (from 0 to 1)
    vec2 uv = gl_FragCoord.xy / resolution.xy;

    // Scale UV coordinates
    uv *= 10.0;

    // Create a striped pattern
    float stripes = step(0.5, fract(uv.x));

    // Compute the partial derivative of the stripes pattern with respect to x
    float dx = dFdx(stripes);

    // Visualize the rate of change of the stripes pattern
    vec3 color = vec3(abs(dx));

    // Output the color
    gl_FragColor = vec4(color, 1.0);
}
