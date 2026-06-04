# Push_swap

*Este proyecto ha sido creado como parte del currículo de 42 amendibi y luciamar*

## Descripción
Sobre el papel, Push_swap es un proyecto de algoritmia de 42. El objetivo suena hasta divertido: te dan una lista desordenada de números enteros y tienes que ordenarlos de menor a mayor.

Cualquier persona normal en el mundo real usaría una función de ordenación nativa y se iría a dormir a una hora decente. Pero aquí no hacemos eso. Aquí nos gusta el sufrimiento.

Para ordenar los números, nos obligan a usar únicamente dos pilas (Stack A y Stack B) y un set de movimientos tan limitados y frustrantes que te hacen cuestionar cada decisión vital que te llevó a estudiar programación. Empiezas con todos los números en el Stack A, el Stack B está vacío, y tienes que pasarlos de un lado a otro hasta que A quede ordenado. Y no, no puedes simplemente crear un array auxiliar y copiar las cosas, ¡OJALÁ!

### Movimientos permitidos (nos cortan las alas)

No podemos manipular la memoria a nuestro antojo. Solo tenemos permitidas estas instrucciones:

- Push: Empuja el primer elemento del stack al primer lugar del otro.
- Swap: Intercambia los dos primeros elementos de un stack.
- Rotación: Coloca el primer elemento del stack en última posición y desplaza todos hacia arriba.
- Rotación inversa: Coloca el último elemento del stack en primera posición y desplaca todos hacia abajo.

### Algoritmo simple

Un algoritmo O(n²) va comparando elementos una y otra vez hasta que acaba revisándolo casi todo con todo. Con pocos datos funciona sin drama, pero cuando la lista crece te da tiempo a ir a por el café. Es fácil de programar, pero se agobia con muchos datos.

### Algoritmo intermedio

Un algoritmo O(n√n) crece más rápido que uno lineal, pero bastante más lento que uno cuadrático. No revisa absolutamente todas las combinaciones como hace O(n²), pero sigue siendo muy mejorable, suficiente como para sentirse productivo, pero sin agobiarse.

#### Two Fase Chunk Sort
- **Idea general**. El problema de ordenar com dos stacks es que no puedes acceder a los elementos del medio directamente - solo puedes trabajar con el tope. La idea del chunk sort es `dividir el problema grande en trozos pequeños` para no tener que buscar por todo el stack cada vez.

**Dos Fases**

    1. Vaciar A hacia B, ellemento a elemento, pero en grupos ordenados.
    2. Reconstruir A desde B extrayendo siempre el valor mayor.

**Fase Previa**
```replace_with_ranks``` Antes de hace nada, convertimos los valores reales del stack en `rangos`.

**¿Por qué?** Porque los valores originales pueden ser cualquier número negativo, con huecos enormes entre ellos, lo que sea. Con rangos siempre tenemos númers de 0 a n-1, contiguos y predecibles. Eso nos permite hacer la división en chunks de forma uniforme con una simple división entera.

La implementación compara cada elemento contra todos los demás y cuenta cuántos son menores qu él.  Ese conteo es su rango. Es O(n²) pero solo se ejecuta 1 vez al inicio.

**¿Por qué √n?** Supongamos que tienes n elementos y los divides en `k chunks de tamaño s` donde `k*s = n`.

En la FASE 1, para cada elemento tienes que buscarlo en A (coste medio n/2 rotaciones) y empujarlo. 

Total: `n(n/2)` rotaciones. Eso sería O(n²)igual que sort_simple → No ganamos nada.

- *TRUCO*. `NO BUSCAS UNO A UNO` buscas el más cercanoañl tope `dentro del chunk actual`. Como los elementos del chunk están dispersos por todo A, el elemento más cercano al tope (o al fondo, buscas los dos) está a una distancia promedio de `n /(elementos_del_chunk) = n / s`

### Algoritmo complejo

Un algoritmo O(n log n) sabe organizarse bien y por eso puede manejar muchísimos datos sin venirse abajo. Divide el problema en partes pequeñas y evita hacer trabajo innecesario. Básicamente es la morra de los plumones, en un trabajo en grupo la que lo hace todo mientras los O(n²) están haciendo la pitipausa.

### Algoritmo adaptativo

## Instrucciones

### Compilación y ejecución

## Recursos

## IA

Durante el desarrollo del proyecto se ha utilizado inteligencia artificial como soporte técnico para la resolución de dudas, depuración y mejora de la comprensión del algoritmo. En concreto, la IA ha sido útil para aclarar conceptos relacionados con la lógica de ordenación, la optimización de movimientos en push_swap y la detección de errores en la implementación. Adicionalmente, ha desempeñado ocasionalmente el papel de confidente durante largas sesiones de errores, segfaults y bucles infinitos.
Aun así, todas las decisiones finales y la implementación del código han sido realizadas por el equipo, utilizando la IA únicamente como herramienta de apoyo y nunca como sustituto del trabajo propio.


## Contribuciones del Equipo

## Dedicatoria especial

Este proyecto se lo dedicamos a todos los cafés, redbulls, monsters, noches largas y momentos de 'esto no funciona' que hicieron posible este proyecto. Agradecimiento especial también al que decidió que las ventanas no debían poder abrirse lo suficiente para que entre una persona; sin él no estaríamos aquí (literalmente).
