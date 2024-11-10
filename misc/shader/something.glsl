#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform float u_time;

vec3 sdgHeart( in vec2 p )
{
    float sx = (p.x<0.0)?-1.0:1.0;
    p.x = abs(p.x);
 
    if( p.y+p.x>1.0 )
    {
        const float r = sqrt(2.0)/4.0;
        vec2 q0 = p - vec2(0.25,0.75);
        float l = length(q0);
        vec3 d = vec3(l-r, q0/l);
        d.y *= sx;
        return d;
    }
    else
    {
        vec2 q1 = p - vec2(0.0,1.0);      vec3 d1 = vec3(dot(q1,q1),q1);
        vec2 q2 = p - 0.5*max(p.x+p.y,0.0); vec3 d2 = vec3(dot(q2,q2),q2);
        vec3 d = (d1.x<d2.x) ? d1: d2;
        d.x = sqrt(d.x);
        d.yz /= d.x;
        d *= (p.x>p.y)?1.0:-1.0;
        d.y *= sx;
        return d;
    }
}

void main(){
    float var = abs(3.5*cos(sin(u_time)));
    vec2 uv = ((gl_FragCoord.xy * 2.0 - u_resolution.xy) / u_resolution.y) ;
    uv.y = uv.y +0.2;
    uv = mat2(var,0,0.,var)*uv;
    vec3 shape = sdgHeart(uv);
    float d = shape.x;
    vec3 col = (d>0.) ? vec3(0.8549, 0.5882, 0.3255) : vec3(smoothstep(-0.9,1.0,uv.x),0.0,0.3);
    gl_FragColor = vec4(col,1.0);
}