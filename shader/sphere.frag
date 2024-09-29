#ifdef GL_ES
precision mediump float;
#endif

uniform float u_time;
uniform vec2 u_resolution;

mat3 rotationMatrix(float angle) {
    float s = sin(angle);
    float c = cos(angle);
    return mat3(
        c, 0.0, -s,
        0.0, 1.0, 0.0,
        s, 0.0, c
    );
}

void main() {
    vec2 uv = gl_FragCoord.xy / u_resolution.xy;
    uv = uv * 2.0 - 1.0;
    uv.x *= u_resolution.x / u_resolution.y;

    float angle = u_time * 0.5;
    mat3 rot = rotationMatrix(angle);

    vec3 spherePos = vec3(uv, 0.0);
    float radius = 0.5;
    if (dot(spherePos.xy, spherePos.xy) > radius * radius) {
        discard;
    }

    spherePos.z = sqrt(radius * radius - dot(spherePos.xy, spherePos.xy));
    spherePos = rot * spherePos;

    float lighting = dot(spherePos, vec3(0.9255, 0.2627, 0.1137));
    lighting = clamp(lighting, 0.0, 1.0);

    vec3 color = vec3(0.92) * lighting;
    gl_FragColor = vec4(color, 1.0);
}