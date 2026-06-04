# Push_swap

*Este proyecto ha sido creado como parte del currículo de 42 amendibi y luciamar*

## Descripción
Sobre el papel, Push_swap es un proyecto de algoritmia de 42. El objetivo suena hasta divertido: te dan una lista desordenada de números enteros y tienes que ordenarlos de menor a mayor.

Cualquier persona normal en el mundo real usaría una función de ordenación nativa y se iría a dormir a una hora decente. Pero aquí no hacemos eso. Aquí nos gusta el sufrimiento.

Para ordenar los números, nos obligan a usar únicamente dos pilas (Stack A y Stack B) y un set de movimientos tan limitados y frustrantes que te hacen cuestionar cada decisión vital que te llevó a estudiar programación. Empiezas con todos los números en el Stack A, el Stack B está vacío, y tienes que pasarlos de un lado a otro hasta que A quede ordenado. Y no, no puedes simplemente crear un array auxiliar y copiar las cosas, ¡OJALÁ!

---

### Movimientos permitidos (nos cortan las alas)

No podemos manipular la memoria a nuestro antojo. Solo tenemos permitidas estas instrucciones:

- Push: Empuja el primer elemento del stack al primer lugar del otro.
- Swap: Intercambia los dos primeros elementos de un stack.
- Rotación: Coloca el primer elemento del stack en última posición y desplaza todos hacia arriba.
- Rotación inversa: Coloca el último elemento del stack en primera posición y desplaca todos hacia abajo.

### Algoritmo simple

Un algoritmo $O(n^2)$ va comparando elementos una y otra vez hasta que acaba revisándolo casi todo con todo. Con pocos datos funciona sin drama, pero cuando la lista crece te da tiempo a ir a por el café. Es fácil de programar, pero se agobia con muchos datos.

#### Insertion Sort adaptado a dos stacks
> **Idea general:** El problema de ordenar con dos stacks es que no puedes acceder a los elementos del medio directamente, solo puedes trabajar con el tope. La idea del insertion sort adaptado es ir colocando cada elemento en su posición correcta dentro del otro stack, manteniendo B ordenado en todo momento.

#### Dos fases
1. Vaciar A hacia B elemento a elemento, insertando cada uno en su posición correcta.
2. Devolver todo de B a A.

* **Fase 1 — Inserción ordenada en B:** Para cada elemento del tope de A, buscamos en B la posición donde debe ir: el hueco entre el primer elemento mayor y el primero menor. Rotamos B hasta esa posición (eligiendo el camino más corto, por arriba o por abajo) y hacemos `pb`.
* **Fase 2 — Volcado a A:** Una vez B está ordenado de mayor a menor, basta con hacer `pa` repetidamente. B ya está en el orden correcto para que A quede ordenado de menor a mayor.

> **¿Por qué $O(n^2)$?** Para cada uno de los $n$ elementos hay que buscar su posición en B, lo que cuesta como mucho $n/2$ rotaciones de media. Total: $n \times (n/2)$ operaciones $\rightarrow$ $O(n^2)$. Con listas pequeñas o casi ordenadas eso no duele, pero con 500 elementos ya empieza a notarse.

---

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
Un algoritmo $O(n \log n)$ sabe organizarse bien y por eso puede manejar muchísimos datos sin venirse abajo. Divide el problema en partes pequeñas y evita hacer trabajo innecesario. Básicamente es la morra de los plumones, en un trabajo en grupo la que lo hace todo mientras los $O(n^2)$ están haciendo la pitipausa.

### Radix Sort bit a bit
> **Idea general:** En lugar de comparar valores entre sí, Radix Sort procesa los números por sus bits, de menor a mayor peso. En cada pasada separa los elementos según si su bit actual es 0 o 1, y al final de todas las pasadas el stack queda ordenado.

#### Fase previa
* **`replace_with_ranks`:** Igual que en el algoritmo intermedio, convertimos los valores originales en rangos de $0$ a $n-1$ antes de empezar. Los valores reales no importan; lo que importa es su posición relativa. Con rangos los bits son predecibles y el número de pasadas necesarias es exactamente $\lceil\log_2(n)\rceil$.

#### El proceso bit a bit
Por cada bit, de menos significativo a más significativo:
1. Recorremos A entero una vez.
2. Si el bit actual del tope es 0 $\rightarrow$ `ra` (se queda en A).
3. Si el bit actual del tope es 1 $\rightarrow$ `pb` (se va a B).
4. Al terminar el recorrido, volcamos todo B de vuelta a A con `pa`.

Después de $k$ pasadas (donde $k$ es el número de bits del rango máximo), A está ordenado.

> **¿Por qué $O(n \log n)$?** Hacemos $\log_2(n)$ pasadas y cada pasada recorre los $n$ elementos una vez. Total: $n \times \log_2(n)$ operaciones. Sin comparaciones, sin búsquedas, sin backtracking. Es el más eficiente del proyecto y también el que más cuesta ver funcionar la primera vez.

---

### Algoritmo Adaptativo
Un algoritmo que no se casa con nadie. Antes de ponerse a ordenar, mide el nivel de desorden de la lista y elige el más adecuado para esa situación concreta.

### Dispatcher por nivel de desorden
> **Idea general:** No tiene sentido usar un cañón para matar una mosca, ni un matamoscas para derribar un avión. El dispatcher mide el caos antes de actuar y delega en el algoritmo que mejor se ajusta a cada caso.

#### ¿Cómo se mide el desorden?
Calculamos qué proporción de elementos están fuera de su posición final correcta. El resultado es un valor entre 0 (perfectamente ordenado) y 1 (caos total).

#### Criterios de selección

| Desorden | Algoritmo elegido | Motivo |
| :--- | :--- | :--- |
| **< 20%** | Simple ($O(n^2)$) | Pocos elementos fuera de sitio, barato recolocarlos. |
| **20% — 50%** | Intermedio ($O(n\sqrt{n})$) | Desorden moderado, los *chunks* son más eficientes. |
| **> 50%** | Complejo ($O(n \log n)$) | Lista muy revuelta, Radix amortiza su coste. |

#### ¿Por qué merece la pena?
Porque el coste real de un algoritmo no solo depende de $n$, sino del estado inicial de los datos. Un $O(n \log n)$ aplicado a una lista casi ordenada hace más operaciones de las necesarias comparado con un $O(n^2)$ bien usado. 

El dispatcher convierte esa decisión en automática, lo que hace que el proyecto no sea solo "ordena números" sino **"ordena números de forma inteligente"**.

---

### Algoritmo adaptativo
Un algoritmo que no se casa con nadie. Antes de ponerse a ordenar, mide el nivel de desorden de la lista y elige el más adecuado para esa situación concreta.

### Dispatcher por nivel de desorden
> **Idea general:** No tiene sentido usar un cañón para matar una mosca, ni un matamoscas para derribar un avión. El dispatcher mide el caos antes de actuar y delega en el algoritmo que mejor se ajusta a cada caso.

#### ¿Cómo se mide el desorden?
Calculamos qué proporción de elementos están fuera de su posición final correcta. El resultado es un valor entre 0 (perfectamente ordenado) y 1 (caos total).

#### Criterios de selección

| Desorden | Algoritmo elegido | Motivo |
| :--- | :--- | :--- |
| **< 20%** | Simple ($O(n^2)$) | Pocos elementos fuera de sitio, barato recolocarlos. |
| **20% — 50%** | Intermedio ($O(n\sqrt{n})$) | Desorden moderado, los *chunks* son más eficientes. |
| **> 50%** | Complejo ($O(n \log n)$) | Lista muy revuelta, Radix amortiza su coste. |

#### ¿Por qué merece la pena?
Porque el coste real de un algoritmo no solo depende de $n$, sino del estado inicial de los datos. Un $O(n \log n)$ aplicado a una lista casi ordenada hace más operaciones de las necesarias comparado con un $O(n^2)$ bien usado. 

El dispatcher convierte esa decisión en automática, lo que hace que el proyecto no sea solo "ordena números" sino **"ordena números de forma inteligente"**.

---

## Instrucciones

### Compilación y ejecución

Clona el repositorio y compila con `make`:

```bash
git clone https://github.com/amendibi/Push_swap.git
cd Push_swap
make
```

Esto genera el ejecutable `push_swap`. Para usarlo, pásale los números como argumentos:

```bash
./push_swap 4 67 3 87 23
```

El programa imprimirá la lista de movimientos necesarios para ordenar la lista. Para contar cuántos movimientos usa:

```bash
./push_swap 4 67 3 87 23 | wc -l
```

Para verificar que los movimientos son correctos puedes usar el checker oficial de 42:

```bash
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

Si todo va bien, el checker devuelve `OK`. Si no, `KO`, y eso significa que algo salió muy mal y probablemente ya lo sabías.

Para limpiar los archivos objeto:

```bash
make clean   # elimina los .o
make fclean  # elimina los .o y el ejecutable
make re      # fclean + make
```

---

## Recursos

Algunas referencias que nos fueron útiles durante el desarrollo:

- [Visualizador de push_swap](https://github.com/o-reo/push_swap_visualizer) — imprescindible para ver qué está haciendo tu algoritmo en tiempo real y entender por qué está mal cuando lo está.
- [The Coding Train — Radix Sort](https://www.youtube.com/watch?v=LyRWppObda4) — buena explicación visual de cómo funciona el ordenamiento por bits.
- [Explicación de Chunk Sort](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) — artículo que explica la lógica detrás del chunk sort aplicado a push_swap.
- [42 Docs — Push_swap](https://harm-smits.github.io/42docs/projects/push_swap) — documentación no oficial pero muy completa sobre el proyecto.

---

## IA

Durante el desarrollo del proyecto se ha utilizado inteligencia artificial como soporte técnico para la resolución de dudas, depuración y mejora de la comprensión del algoritmo. En concreto, la IA ha sido útil para aclarar conceptos relacionados con la lógica de ordenación, la optimización de movimientos en push_swap y la detección de errores en la implementación. Adicionalmente, ha desempeñado ocasionalmente el papel de confidente durante largas sesiones de errores, segfaults y bucles infinitos.
Aun así, todas las decisiones finales y la implementación del código han sido realizadas por el equipo, utilizando la IA únicamente como herramienta de apoyo y nunca como sustituto del trabajo propio.


## Contribuciones del Equipo

“Hemos hecho todo lo posible y un poco más de lo que era posible, si es que eso ha sido posible. Y hemos hecho todo lo posible e incluso lo imposible, si es que lo imposible ha sido posible”.

Dicho esto, este proyecto ha sido, ante todo, un gran viaje de aprendizaje. Hemos aprendido a respetar al prójimo y a encontrar un punto medio donde antes había diferencias. Hemos aprendido que la comunicación es la clave de todo, sin importar el género, el origen o la procedencia; aquí todos tenemos cabida en cualquier sector. Al fin y al cabo, todos hablamos el mismo idioma: el lenguaje de la programación (aunque, bueno... cada cual que elija el suyo, ¡que algunos dan un poco de repelús!).

Queremos dedicarle este trabajo:

- A todos los que han compartido su sabiduría con nosotros día a día.

- A Amparo, por su apoyo incondicional y su dosis diaria de positividad.

- A los cafés quemados y al Red Bull (prometemos que no somos adictos a la cafeína, solo es una relación de conveniencia).

Y, por supuesto, te lo dedicamos a ti, que te has interesado en nuestro proyecto. Gracias por tu esfuerzo, por tu tiempo y por valorar el trabajo que hay detrás de este proyecto.

A ti, de corazón: gracias.

## Dedicatoria especial

Este proyecto se lo dedicamos a todos los cafés, redbulls, monsters, noches largas y momentos de 'esto no funciona' que hicieron posible este proyecto. Agradecimiento especial también al que decidió que las ventanas no debían poder abrirse lo suficiente para que entre una persona; sin él no estaríamos aquí (literalmente).
