#include <iostream>

using namespace std;

struct Nodo {

  Nodo *siguiente;
  int valor;
  bool eshead;
};

auto crealista(Nodo *&nodo, int nodos, Nodo *head) -> Nodo *;
void imprimelista(Nodo *nodo);
void borramemoria(Nodo *nodo);
void agreganodo(Nodo *inicio, Nodo *nodoagregar);

auto crealista(Nodo *&nodo, int nodos, Nodo *head) -> Nodo * {

  Nodo *nuevonodo =
      new Nodo{.siguiente = nullptr, .valor = nodo->valor + 1, .eshead = false};

  if (nuevonodo->valor == nodos) {

    return head;
  }

  nodo->siguiente = nuevonodo;

  return crealista(nuevonodo, nodos, head);
}

void imprimelista(Nodo *nodo) {

  cout << nodo->valor << "|" << nodo << "|" << nodo->siguiente << "\n";
  if (nodo->siguiente != nullptr) {

    imprimelista(nodo->siguiente);
  } else {

    return;
  }
}

void borramemoria(Nodo *nodo) {

  Nodo *nsig = nodo->siguiente;
  delete nodo;
  nodo = nullptr;

  if (nsig != nullptr) {
    borramemoria(nsig);
  } else {
    return;
  }
}

void agreganodo(Nodo *nodo, Nodo *nodoagregar) {

  // Nodo *nodosig = nodo->siguiente;
  if (nodo->siguiente == nullptr) {

    nodoagregar->valor = nodo->valor + 1;
    nodo->siguiente = nodoagregar;

    return;
  } else {
    agreganodo(nodo->siguiente, nodoagregar);
  }
}

auto main(int argc, char *argv[]) -> int {

  const int NODOS = 5;

  cout << "hola termux" << "\n";

  Nodo *head = new Nodo;
  head->valor = 0;

  Nodo *head2 = crealista(head, NODOS, head);

  imprimelista(head2);

  Nodo *nodoagregar = new Nodo;

  agreganodo(head2, nodoagregar);

  imprimelista(head2);

  borramemoria(head2);

  // delete head2;
  // head2 = nullptr;

  return 0;
}
