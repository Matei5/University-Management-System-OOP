# Proiect 2 - POO - Subiect: Materie

- [x] O interfață care definește funcțiile virtuale pure
- [x] O clasa abstractă (care implementeaza anumite metode ale interfeței, dar nu pe toate)
- [x] Variabila și funcție statică
- [x] Variabila constantă
- [x] 2-3 clase care moștenesc clasa abstracta, vector/listă/colecție de pointeri către bază
- [x] Utilizarea corectă a claselor polimorfice, de ilustrat în main() pe o colecție de obiecte de tip Baza cu dynamic_cast, să se apeleze toate metodele obiectului de tip derivată.
- [x] Resurse alocate dinamic în cel puțin una din clase + regula celor 5 (cc/op=/destructor/constructor mutare/op= pentru mutare)
- [x] Destructor virtual pentru resursele alocate dinamic, obligatoriu cel puțin o clasă cu resurse alocate dinamic (și eliberate corespunzător).
- [x] Vector/List/Colectie de pointeri către Bază cu downcasting cu dynamic_cast
- [ ] Operator de afișare definit în clasa abstractă care apelează o funcție virtuală de afișare, a obiectului derivat, precum în lab06.
- [x] Minim 2 funcții virtuale diferite de Destructor și Afisare()
- [x] Cel puțin o funcție virtuala care este suprascrisă doar în clasa abstractă și în niciuna din derivate
- [x] 1-2 funcții comune non-virtuale def inite in clasa abstractă
- [ ] Minim o clasă proprie pentru excepții, și folosirea mecanismului de excepții pe parcursul programului.
- [x] Toate atributele vor fi definite private (sau protected în cazul moștenirii). Important este să nu fie niciodată declarate atribute public în cadrul claselor.
- [x] Utilizarea static_cast unde este nevoie
- [x] Metodele interne clasei (funcțiile ajutătoare), de asemenea private/protected (depinde dacă avem nevoie de ele în clasa derivată) – nu are sens să le poată apela utilizatorul, ci doar voi din interior.
- [x] Utilizare const peste tot unde este posibil (în mod special când trimiteți prin referință fără să modificați obiectul sau la metodele care nu modifică obiectul this)
- [x] Toate metodele definite trebuiesc și apelate/testate în cadrul claselor sau în main(), altfel nu are sens să le fi definit.
- [x] Fără variabile globale și fără cale absoluta (C:/...), doar cale relativa (../../dir)
- [x] FĂRĂ using namespace std – niciodata în .h, tolerabil în .cpp, dar tot neindicat; Observație: sunteți liberi să îl folosiți la colocviu, unde orice secundă câștigată conteaza.
- [x] Proiectul să fie încărcat pe GitHub fără erori de compilare, cu cât mai multe commit-uri relevante pe parcurs cu mesaje descriptive, care să ilustreze progresul. Munca pe parcurs va fi luată în considerare subiectiv la notare în plus. Insă, studenții cu proiecte cu un singur commit sau doar pe final vor fi întrebați mai în amănunt la prezentare.
- [x] README.md care explică proiectul (numele proiectului, scopul proiectului, structura claselor, funcționalități)
- [x] .gitignore pentru fișierele pe care nu doriți să le includeți (nu includeți alte fișiere decât cele necesare proiectului, și să nu includeți fișiere executabile pe GitHub sau fișiere obiect ”.o”, doar cod sursă!!)
- [x] Fișier de input pentru datele citite de la tastatură. Fișierul de input este necesar încât să nu fiu nevoit să introduc manual datele pentru a vă testa proiectul. Puteți să vă redirecționați și voi input-ul din fișier în terminal din același motiv (exemplificat în Lab04).

## Clasa Ipersoana

1. Metode publice:
* getFullName: returneaza numele si prenumele unei persoane

## Clasa AbstractStudent

Mostenire Ipersoana
1.  Membri:
* Nume: Numele studentului.
* Prenume: Prenumele studentului.
* Nota: Nota studentului.
2. Metode publice:
* Overide getFullName
* getNota(): Returnează nota studentului.
* setNota(float n): Setează nota studentului.

## Clasa StudentAn1:

Mostenire AbstractStudent
1.  Membri:
* static An: Anul studentului
2. Metode publice:
* operator+(float n): Creste/Scade nota studentului
* getAn(): returneaza static int An

## Clasa StudentAn2:

Mostenire AbstractStudent
1.  Membri:
* An: Anul studentului
2. Metode publice:
* operator+(float n): Creste/Scade nota studentului
* * getAn(): returneaza static int An


## Clasa Profesor:

Mostenire Ipersoana
1. Membri:
* Nume: Numele profesorului.
* Prenume: Prenumele profesorului.
* Email: Adresa de email a profesorului.
2. Metode publice:
* Overide getFullName
* getEmail(): Returnează adresa de email a profesorului.

## Clasa Examen:

1. Membri:
* Zi, Luna, An: Data examenului.
* Ora: Ora examenului (in format militar).
* TimpDeLucruInMinute: Durata examenului în minute.
* NrSubiecte: Numărul de subiecte ale examenului.
2. Metode publice:
* getAn(): Returnează anul examenului.

## Clasa Materie:

1. Membri:
* NumeMaterie: Numele materiei.
* const An, Semestru: Anul și semestrul în care se desfășoară materia.
* Studenti: Vector de obiecte de tip Student care reprezintă studenții din materie.
* Examen, Restanta: Obiecte de tip Examen care reprezintă examenul și restanța materiei.
* CadruDidactic: Obiect de tip Profesor care reprezintă profesorul care preda materia.
2. Metode publice:
* getNumarStudenti(): Returnează numărul de studenți din materie.
* getEmailProfesor(): Returnează adresa de email a profesorului materiei.
* getNotaStudent(int n): Returnează nota studentului identificat de indexul n.
* getAnRestanta(): Returnează anul examenului de restanță pentru materie.
* schimbareProfesor(const Profesor &prof): Schimbă profesorul care predă materia cu un alt profesor dat.
* operator+=(const Student &s): Adaugă un nou student la lista de studenți ai materiei.
