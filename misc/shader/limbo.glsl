#ifdef GL_ES
precision mediump float;
#endif

const float primes[2] = float[2](1.0,2.0);
void main() {
   vec2 uv = 0.07*(gl_FragCoord.xy);
   int x_int = int(uv.x);
   float x_float = float(x_int);
   int y_int = int(uv.x);
   float y_float = float(y_int);
   vec3 color = vec3(0.0,0.0,0.0);
   if (mod(uv.x,4.0) < 2.1 && mod(uv.x,4.0) > 1.9){
      color = vec3(1.0,0.0,0.0);
   }
   gl_FragColor = vec4(color,1.0);
}


//(ux.x,ux.y)