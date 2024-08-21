import * as THREE from "three";
import { OrbitControls } from "three/examples/jsm/controls/OrbitControls.js";

// Renderer
const w = window.innerWidth;
const h = window.innerHeight;
const renderer = new THREE.WebGLRenderer({ antialias: true });
renderer.setSize(w, h);
document.body.appendChild(renderer.domElement);

// Camera
const fov = 75;
const aspect = w / h;
const near = 0.1;
const far = 10;
const camera = new THREE.PerspectiveCamera(fov, aspect, near, far);
camera.position.z = 2;

const scene = new THREE.Scene();

const controls = new OrbitControls(camera, renderer.domElement);

const geo = new THREE.PlaneGeometry(2, 2);

const uniforms = {
  time: { type: "f", value: 0 },
  resolution: { type: "v2", value: new THREE.Vector2(w, h) },
};

const fragmentShader = `
uniform float time;
uniform vec2 resolution;

void main() {
  vec2 uv = gl_FragCoord.xy / resolution.xy;
  vec2 center = vec2(0.5, 0.5);
  float d = distance(uv, center);
  float alpha = smoothstep(0.5, 0.55, d);
  gl_FragColor = vec4(1.0, 0.0, 0.0, alpha);
}
`;

const material = new THREE.ShaderMaterial({
  uniforms,
  vertexShader: `
void main() {
  gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);
}
`,
  fragmentShader,
});

const mesh = new THREE.Mesh(geo, material);
scene.add(mesh);

const hemiLight = new THREE.HemisphereLight("cyan", "red");
scene.add(hemiLight);

function animate(t = 0) {
  requestAnimationFrame(animate);
  uniforms.time.value = t * 0.001;
  renderer.render(scene, camera);
  controls.update();
}
animate();
