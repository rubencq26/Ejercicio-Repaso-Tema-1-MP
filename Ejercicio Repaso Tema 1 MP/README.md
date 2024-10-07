



## EJERCICIO DE REPASO DEL TEMA 1
---

Deduce qu� m�todos y funciones hay que implementar para que se pueda ejecutar el siguiente `main()`.

```cpp
int main() {
    socio c1("Juan Jose", 27);     // socio de nombre "Juan Jose" y edad 27 a�os
    socio c2("Paloma", 20);        // socio de nombre "Paloma" y edad 20 a�os
    socio c3 = c2;                 // el socio c3 tendr� el mismo nombre y edad que c2
    c2.setnombre("Paloma Maria");  // cambia el nombre del socio c2
    c1.ver(); c2.ver(); c3.ver(); cout << endl; // muestra por pantalla nombre y edad de socios c1, c2 y c3
    socio c4(c2);                  // crea el socio c4 con los mismos datos que el socio c2
    c2.ver(); c4.ver(); cout << endl;

    if (c4 == c2)  // pregunta si los socios c4 y c2 se llaman igual y tienen la misma edad
        cout << c4 << " == " << c2 << endl;
    else
        cout << c4 << " != " << c2 << endl;
    
    c2 = c1;       // los socios c3, c2 y c1 se van a llamar igual y tendr�n la misma edad
    cout << c1 << "," << c2 << "," << c3 << endl;

    c3.setnombre("Ana");
    c2 = c3;
    c1.setnombre("Luis");

    socio t[3];
    t[0]=c1; t[1]=c2; t[2]=c3;

    for(int i=0; i<3; i++)
        cout << "t[" << i << "] es el objeto "
             << "[long=" << t[i] << "]" << t[i] << endl;

    system("PAUSE"); return EXIT_SUCCESS;
}
```

---

Implementa los m�todos necesarios y realiza el ejercicio considerando que:

a) Para guardar el nombre usamos un array est�tico `char nombre[30];`

b) Para guardar el nombre usamos un array din�mico `char *nombre;`
   1. Elimina el constructor por defecto y ve lo que ocurre.
   2. Elimina el constructor de copia y ve lo que ocurre.
   3. Elimina el operador `=` y ve lo que ocurre.
   4. Elimina el destructor y ve lo que ocurre.

c) Tanto para el apartado a) como para el apartado b), declara el atributo edad constante y el objeto `c4` constante (corrige los errores si los hay).  
   **�Qu� pasa con el operador de asignaci�n (operador `=`)?**

d) Supongamos que queremos que cada socio creado tenga un n�mero de socio �nico. Indica los cambios que hay que realizar en el programa para que, cada vez que se cree un socio, el programa le asigne autom�ticamente un n�mero diferente a cada socio.

e) Si adem�s queremos que todos los socios paguen la misma cuota de abono...  
   **�Qu� m�s cambios habr� que realizar?** Implementa m�todos que permitan consultar y modificar la cuota de abono com�n a todos los socios.

--- 

