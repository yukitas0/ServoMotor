# Servidor Motor de 2WD MiniQ

Este proyecto consiste en el desarrollo de un servidor motor para un robot de 2 ruedas (2WD) del tipo MiniQ. El objetivo es controlar el movimiento del robot a través de comandos enviados desde una aplicación o desde una interfaz de usuario.

## Descripción del Proyecto

El servidor motor permite controlar la velocidad y dirección de las ruedas del MiniQ mediante una conexión serial o inalámbrica. Proporciona una interfaz sencilla para enviar comandos de movimiento y ajustar los parámetros de velocidad.

## Características

- Control de velocidad independiente para cada rueda.
- Soporte para dirección diferencial.
- Interfaz de comunicación serial o inalámbrica.
- Compatible con plataformas Arduino y similares.
- Documentación detallada para facilitar la integración y desarrollo.

## Requisitos

- Plataforma de desarrollo Arduino.
- Hardware compatible con el robot MiniQ (chasis, motores, controladores, etc.).
- Conexión serial o inalámbrica establecida entre el servidor motor y el dispositivo de control.

## Instalación

1. Clonar el repositorio del servidor motor.
2. Instalar las bibliotecas y dependencias necesarias.
3. Compilar el código y cargarlo en la plataforma de desarrollo.

## Uso

1. Conectar el servidor motor al MiniQ según las especificaciones del hardware.
2. Establecer la comunicación con el servidor motor desde la aplicación o dispositivo de control.
3. Enviar comandos de movimiento para controlar el robot.

Ejemplo de código para enviar comandos desde Arduino:

```arduino
#include <ServidorMotor2WD.h>

ServidorMotor2WD motorServer;

void setup() {
  // Inicialización del servidor motor
  motorServer.begin();
}

void loop() {
  // Ejemplo de comando de movimiento: Avanzar a velocidad máxima
  motorServer.avanzarMaxVelocidad();
  delay(1000);
  // Detener el movimiento
  motorServer.detener();
  delay(500);
  // Ejemplo de comando de movimiento: Girar a la izquierda a velocidad media
  motorServer.girarIzquierda(50);
  delay(1000);
  // Detener el movimiento
  motorServer.detener();
  delay(500);
}
