#ifdef GL_ES
precision highp float;
#endif

// Enable the standard derivatives extension...
#extension GL_OES_standard_derivatives : enable
uniform vec2 u_resolution;

void main() {
   vec2 uv = ((gl_FragCoord.xy) / u_resolution.y) ;
   gl_FragColor = vec4(uv,0.0,1.0);
}
