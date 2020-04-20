# Brazo robotico (simulacion) - Poryecto final de Circuitos IV

_Para el proyecto final de Circuitos IV, se decidio hacer un brazo robotico con microcontrolador avr y programarlo con c puro, sin embargo, debido a causas fuera del control de muchos, solo se presenta la seimulación del funcionamiento de las partes mas basicas del mismo los cuales son los motores y el microcontrolador propiamente dicho._

En esta documentación se encuentra todo lo relacionado al proyecto, desde funcionamiento hasta el proceso de creación.

## ***Para ello empecemos con el circuito de simulacion...***

Al principio se habia dicho que este proyecto se iba a realizar con joysticks o potenciometros, pero se decicio al final hacer con pulsadores, de todas formas no esta de mas decir que los robots industriales, o al menos la mayoria funcionan o con botones fisicos o digitales o simplmente son "autónomios".

Para la simulación se utilizo el software de proteus, donde se simulaba el codigo funcionando con los componentes utilizados. Hablando de materiales, los que se usaron son los siguientes:

* El Atmega16; luego hablaremos de el a detalle.
* 5 pulsadores.
* 5 resistenacias de 1k.
* 2 servo motores.
* un motor DC (para la garra).
* un driver L293D.
* un switch.
* fuente de alimentacion para el circuito.
* fuente de alimentacion externa para los motores.

No hay mucho que mencionar sobre la mayoria de los materiales ya que son muy comunes, de todas formas el circuito esta en este repositorio

[AQUI LA IMAGEN DEL CIRCUITO](https://github.com/Bobertwest/Proyecto-final/blob/master/circuito.png)

## Funcionamiento

Tenemos el circuito, y sabemos lo que hace, bien; pero ¿como funciona realmente o como se opera?

El circuito tiene una serie de pulsadores, donde 4 estan destinados a controlar la posicion de los dos servomotores, dos para cada servo. Al iniciar el programa, los servos se posicionan en un punto especifico, llamemosle _"set 0"_. como se dijo, cada servo funciona con dos pulsadores donde al presionar uno, el servo aumentara su posicion de uno en uno hasta que este se deje de presionar, de igual manera con el otro pulsador, pero en sentido contrario.

para entender como pasa esto hay que entender bien como funciona el servo motor y el PWM
