#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;  // Resolution of the canvas

void main() {
    // Normalize the pixel coordinates to the range [-1, 1]
    vec2 uv = (gl_FragCoord.xy / u_resolution) * 2.0 - 1.0;

    // Calculate the distance from the center
    float dist = length(uv);

    // Set the circle radius
    float radius = 0.5;

    // Determine the color of the pixel
    vec3 color = vec3(0.0);

    // If the distance is less than the radius, color the pixel white
    if (dist < radius) {
        color = vec3(1.0);
    }

    // Set the fragment color
    gl_FragColor = vec4(color, 1.0);
}
