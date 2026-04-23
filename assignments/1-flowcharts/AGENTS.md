# Guía de Diagramas de Flujo — Criterios del Profesor Kevin Ronald Lopez Orellana

Este documento contiene instrucciones precisas sobre cómo elaborar diagramas de flujo según los criterios del profesor. Toda la información fue extraída directamente de las clases del 2, 4 y 9 de febrero de 2026 (SIS-111).

---

## 1. Simbología Obligatoria

Usar **exactamente** estos símbolos sin excepción:

| Símbolo | Forma | Contenido esperado |
| :--- | :--- | :--- |
| **Inicio / Fin** | Óvalo (o círculo) | Debe decir literalmente `Inicio` o `Fin`. |
| **Entrada de datos** | Paralelogramo | Variables que el usuario ingresa (ej. `Leer L`). |
| **Proceso** | Rectángulo | Operaciones, fórmulas, asignaciones e instanciaciones. |
| **Salida / Mostrar** | Rectángulo con curva en la base | Resultado que se muestra al usuario. |
| **Condicional** | Rombo | Pregunta binaria (Sí/No, Verdadero/Falso). |
| **Conector** | Círculo pequeño | Continuación en otra página. Se numera: 1, 2, 3… |

> [!CAUTION]
> No confundir el rectángulo de Proceso con el rectángulo curvo de Salida. La curva en la base es lo que los distingue.

---

## 2. Estructura Estándar de un Diagrama (Los 6 Pasos)

Todo diagrama debe seguir **este orden exacto**:

### Paso 1 — Inicio
Óvalo con la palabra `Inicio`.

### Paso 2 — Instanciación de variables
Rectángulo donde se **declaran todas las variables con su valor inicial** (normalmente `= 0`).

- Ejemplo: `A = 0`, `m4 = 0`, `cp = 0`.
- Si una variable se pedirá en la Entrada de Datos (paso 3), **no es necesario duplicarla aquí**.
- Las variables que se usarán como contadores o acumuladores **sí deben instanciarse en cero obligatoriamente** para evitar errores de `null`.

### Paso 3 — Entrada de datos
Paralelogramo para capturar los datos que el usuario proporciona.

- Ejemplo: `Leer L` (para el lado de un cuadrado), `Leer N` (para la cantidad de números).

### Paso 4 — Proceso
Rectángulo con la fórmula, cálculo o lógica.

- Ejemplo: `A = L * L`, `porcentaje = (cp * 100) / N`.

### Paso 5 — Salida
Rectángulo curvo mostrando el resultado al usuario.

- Se puede concatenar texto: `"El área es: " + A`.
- La salida debe ser **clara** para el usuario.

### Paso 6 — Fin
Óvalo con la palabra `Fin`.

---

## 3. Reglas de Flujo y Conectividad

- **Dirección:** El diagrama se construye siempre de **arriba hacia abajo**.
- **Conectividad total:** Todos los elementos deben estar conectados por líneas de flujo. No puede haber elementos "huérfanos" (aislados, sin flechas que entren o salgan).
- **Camino del Falso:** Aunque un condicional IF simple no haga nada por el camino del "No", la flecha **debe dibujarse igualmente** y reconectarse al flujo principal. El algoritmo nunca debe "perderse".

---

## 4. Variables y Nomenclatura

### Convención: camelCase
- Primera letra **minúscula**, cada palabra siguiente inicia con **mayúscula**.
- Ejemplo correcto: `areaCuadrado`, `porcentajePositivos`.

### Reglas estrictas
- **Sin acentos:** nunca usar tildes ni caracteres especiales en nombres de variables.
- **Sin empezar con número:** `4m` está **mal**; `m4` está **bien**.
- **Nombres descriptivos:** el nombre debe explicar qué almacena la variable, sin ser excesivamente largo.
- Opciones válidas para un múltiplo de 4: `m4`, `m_4`, `mult4`, `multiplo4`.

### Instanciación
- Toda variable de trabajo (contadores, acumuladores, resultado) se inicializa en `0`.
- Justificación del profesor: `null + 10` no tiene resultado, pero `0 + 10` sí. Instanciar previene errores.

---

## 5. Condicionales (Rombo)

### IF-ELSE (Doble vía)
- Del rombo salen dos caminos: **Sí** y **No**.
- Cada camino lleva a una acción distinta.
- Ambos caminos deben **reconectarse** al flujo principal.

### IF Simple (Vía única)
- Solo se ejecuta una acción por el "Sí".
- Por el "No" no se hace nada, pero **la flecha se dibuja igual** y se reconecta.

### Condiciones independientes vs. encadenadas
- Si un número puede cumplir múltiples condiciones simultáneamente (ej. ser múltiplo de 4 **y** de 7), usar **IFs independientes** (uno tras otro), **no** `else if`.
- `else if` solo se usa cuando las condiciones son mutuamente excluyentes.

### Operadores de comparación
- `=` es para **asignar** (ej. `A = 0`).
- `==` es para **comparar** (ej. `if (A == 0)`).
- Usar un solo `=` en una condición es un **error**.

---

## 6. Operadores Lógicos

### AND (`&&`)
- **Todas** las condiciones deben ser verdaderas.
- Ejemplo: `num % 3 == 0 AND num % 5 == 0` → múltiplo de 3 y de 5 a la vez.

### OR (`||`)
- **Al menos una** condición debe ser verdadera.

### Se pueden combinar
- Ejemplo: `(condición1 AND condición2) OR condición3`.

---

## 7. Bucles

### Ciclo While
- Se usa cuando **no** se sabe cuántas veces se repetirá.
- Basado en una condición lógica; se repite mientras sea verdadera.

### Ciclo For
- Se usa cuando se sabe **exactamente** cuántas veces se repetirá.
- Tiene tres partes claras: **Inicio**, **Fin**, **Incremento/Decremento**.
- Ejemplo: `Para i = 1 hasta N, i++`.

### Incremento/Decremento
- `i++` equivale a `i = i + 1`.
- `i += 2` equivale a `i = i + 2`.
- `i--` equivale a `i = i - 1`.
- Estas son abreviaturas; la operación expandida también es válida.

---

## 8. Patrón Estándar para "N Números"

Cuando el enunciado pide procesar un conjunto de N números, usar **siempre** esta estructura:

```
1. Inicio
2. Declarar variables (contadores, acumuladores) = 0
3. Leer N  ← cuántos números se procesarán
4. Para i = 1 hasta N:
   4a. Leer num  ← solicitar un dato DENTRO del ciclo
   4b. Aplicar la lógica (comparar, contar, sumar)
5. Mostrar resultados finales (FUERA del ciclo)
6. Fin
```

> [!WARNING]
> La variable donde se lee cada número individual (`num`, `dato`, `numero`) **NO puede llamarse igual** que la variable de cantidad total (`N`). Si `N = 5` y dentro del ciclo se reasigna `N = 300`, el ciclo se repetirá 300 veces.

---

## 9. Estrategia para Máximos y Mínimos

### "El primero es la referencia"
1. Al recibir el **primer número** (`i == 1`), asignarlo tanto a `may` como a `men`.
2. Para los siguientes (`i > 1`):
   - Si `num < men` → actualizar `men = num`.
   - Si `num > may` → actualizar `may = num`.
3. La pregunta `i == 1` se cumple **una sola vez**.

Esta estrategia se aplica a: mejor nota, peor nota, más alto, más bajo, etc.

---

## 10. Cálculo de Porcentajes

**Fórmula:**

```
porcentaje = (cantidad_parcial * 100) / cantidad_total
```

- Contar por separado (ej. positivos vs. negativos).
- Calcular el porcentaje **fuera del ciclo**, después de haber contado.
- El cero no es positivo ni negativo. Si hay ceros, los porcentajes no sumarán 100%.

---

## 11. Criterios Psicológicos del Profesor (Qué Valora al Evaluar)

### Lo que prioriza
1. **Comprensión antes de ejecución:** insiste en que si no se entiende el enunciado, no se intente resolver. Primero entender, luego diagramar.
2. **Lectura exacta del enunciado:** distinguir entre "cantidad" y "suma", entre "positivos y negativos" (sin incluir ceros). Un error de lectura produce un diagrama incorrecto.
3. **Especificidad del problema:** un algoritmo debe resolver un problema **concreto**, no genérico.
4. **Conectividad completa:** ningún elemento queda suelto. Todo conectado por flechas.
5. **Instanciación obligatoria:** las variables deben tener valor inicial. No hacerlo es un error técnico.
6. **Diferencia `=` vs `==`:** usar `=` en una condición está **mal**. Es un error que menciona explícitamente.
7. **Independencia de condiciones:** no usar `else if` cuando las condiciones pueden cumplirse simultáneamente. Cada condición se evalúa por separado.
8. **Claridad en la salida:** el resultado debe ser comprensible para el usuario final.

### Lo que penaliza
- Elementos huérfanos (sin conexión al flujo).
- Caminos del "No" sin flecha dibujada.
- Reutilizar el nombre de la variable `N` para leer datos individuales dentro del ciclo.
- Confundir asignación (`=`) con comparación (`==`).
- No instanciar variables.
- Usar `else if` donde se necesitan IFs independientes.
- Confundir "cantidad" con "suma" por no leer bien el enunciado.

### Estilo de razonamiento
- Usa analogías de la vida real para explicar lógica (marcadores, ingredientes, edades en el aula).
- Valora soluciones **optimizadas** (ej. decrementar de 2 en 2 en vez de verificar paridad) pero acepta ambos caminos si la lógica es correcta.
- Enfatiza que la estructura del diagrama es **universal** e independiente del lenguaje.
- Advertencia frecuente: "en un examen podría agregar variantes" (ej. excluir ceros del total).

---

## 12. Resumen de Errores Frecuentes a Evitar

| Error | Corrección |
| :--- | :--- |
| Elemento sin flechas de conexión | Todo debe estar conectado al flujo |
| Camino "No" sin flecha | Dibujar la flecha y reconectar al flujo |
| `=` en una condición | Usar `==` para comparar |
| Variable `N` usada para leer datos dentro del ciclo | Usar un nombre distinto: `num`, `dato`, etc. |
| Variables sin instanciar | Inicializar en `0` antes de usar |
| `else if` cuando las condiciones no son excluyentes | Usar IFs independientes secuenciales |
| Confundir "cantidad" con "suma" | Leer el enunciado con precisión |
| Nombre de variable con acento o que empieza con número | Usar camelCase sin acentos; no iniciar con dígito |
| Salida poco clara | Concatenar texto explicativo con el resultado |


