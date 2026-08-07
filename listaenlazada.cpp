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
void remuevenodo(Nodo *nodo, Nodo **anterior, int valorremover);

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

void removernodo(Nodo *nodo, Nodo **anterior, int valorremover) {

  cout << "En removernodo" << "\n";

  if (nodo->valor != valorremover) {
    if (nodo->siguiente == nullptr) {
      return;
    }

    if (nodo->eshead) {

      removernodo(nodo->siguiente, anterior, valorremover);
    } else {
      if ((*anterior)->siguiente == nodo) {

        removernodo(nodo->siguiente, anterior, valorremover);
      } else {
        (*anterior)->siguiente->siguiente = nodo;

        removernodo(nodo->siguiente, anterior, valorremover);
      }
    }

  } else {

    if (nodo->eshead) {
      nodo->siguiente->eshead = true;
    }
    (*anterior)->siguiente = nodo->siguiente;
    delete nodo;
    nodo = nullptr;
    return;
  }
}

auto main(int argc, char *argv[]) -> int {

  const int NODOS = 5;

  Nodo *head = new Nodo;
  head->valor = 0;
  head->eshead = true;

  head = crealista(head, NODOS, head);

  imprimelista(head);

  Nodo *nodoagregar = new Nodo;

  agreganodo(head, nodoagregar);

  imprimelista(head);

  Nodo **anterior = new Nodo *(head);

  removernodo(head, anterior, 3);

  imprimelista(head);

  borramemoria(head);

  delete anterior;
  anterior = nullptr;

  return 0;
}
