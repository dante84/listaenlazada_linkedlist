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
void agreganodo(Nodo *nodo, Nodo *nodoagregar);
void remuevenodo(Nodo *nodo, int valorremover);

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
  if (!(nodo->siguiente == nullptr)) {

    agreganodo(nodo->siguiente, nodoagregar);
  } else {
    nodoagregar->valor = nodo->valor + 1;
    nodo->siguiente = nodoagregar;

    return;
  }
}

void removernodo(Nodo *nodo, int valorremover) {

  if (nodo->siguiente == nullptr) {
    return;
  }

  if (nodo->valor != valorremover) {
    if (nodo->siguiente->valor == valorremover) {
      Nodo *temp = nodo->siguiente->siguiente;
      delete nodo->siguiente;
      nodo->siguiente = nullptr;
      nodo->siguiente = temp;

    } else {
      removernodo(nodo->siguiente, valorremover);
    }
  } else {

    if (nodo->eshead) {
      nodo->siguiente->eshead = true;
      delete nodo;
      nodo = nullptr;
    }

    return;
  }
}

auto main(int argc, char *argv[]) -> int {

  const int NODOS = 50;
  const int NUMERO_REMOVER = 34;

  Nodo *head = new Nodo;
  head->valor = 0;
  head->eshead = true;

  head = crealista(head, NODOS, head);

  imprimelista(head);

  Nodo *nodoagregar = new Nodo;

  agreganodo(head, nodoagregar);

  imprimelista(head);

  removernodo(head, NUMERO_REMOVER);

  imprimelista(head);

  borramemoria(head);

  return 0;
}
