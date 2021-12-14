# Propuesta de práctica: Arduino con sensor GPS NEO 6M y pantalla de cristal líquido
## Nivel: 3º-4º de ESO
### Propuesta
La idea es programar de forma sencilla una tarjeta Arduino de tipo Nano (o la que mejor te venga) para que lea las coordenadas de un sensor GPS y las pase a una pantalla de cristal líquido LCD. De ese modo, alimentándola con un portapilas o un powerhub, disponemos de un sencillo dispositivo para leer latitud y longitud.
### Utilidad didáctica
En 3º se estudian, entre otros conceptos relacionados con la geometría, el uso de meridianos y paralelos, la latitud y la longitud. Nosotros, en clase, hemos marcado previamente valiéndonos de Internet unos cuantos puntos de nuestro instituto a los que
nos hemos ido desplazando para comprobar si las coordenadas obtenidas por nuestro dispositivo eran correctas. Al mismo tiempo, con el norte como referencia, hemos comprobado
la variación positiva o negativa de latitud y longitud según nos desplazábamos a cada punto cardinal.

En 4º de ESO, por otro lado, en materias como Tecnología o Tecnología Robótica, dependiendo de la familiaridad de cada grupo de alumnos con el uso de la protoboard, la lectura de esquemas
e implementación de circuitos, se puede proponer el montaje de este dispositivo como práctica de taller. Además, si en clase se ha trabajado con Arduino, se puede volcar el código
proporcionado en el microcontrolador como hilo conductor del estudio de conceptos como el uso de funciones aparte de ***setup()*** o ***void()***, la función del puerto
serie, o la comunicación de Arduino como dispositivos I2C.
