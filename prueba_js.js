#!/usr/local/bin/node

//=====================
//  node prueba_js.js
//=====================

//====================================
//  Programa de prueba en javascript
//====================================

//==============
//  Constantes 
//==============
var VEC_LEN = 1000000
var AVERAGING = 1000

//============
//  Vectores 
//============
var A = new Array(VEC_LEN);
var B = new Array(VEC_LEN);

//===============================
//  Llenado con números al azar 
//===============================
for (var i = 0; i < VEC_LEN; ++i) {
  A[i] = Math.random();
  B[i] = Math.random();
}

//====================================
//  Producto escalar de los vectores 
//====================================
var c = 0.0;
var start = new Date().getTime();
for (var j = 0; j < AVERAGING; ++j) {
  c = 0;
  for (var i = 0; i < VEC_LEN; ++i) {
    c += A[i] * B[i];
  }
}

var elapsed = new Date().getTime() - start;

console.log("c:", c);
console.log("For loop:", elapsed / AVERAGING, "ms");

