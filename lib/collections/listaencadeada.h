#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

template <typename T>
struct TElemento{
    TElemento<T> *proximoElemento;
    T data;
};

template <typename T>
struct TLista{
    TElemento<T> *elementoInicial;
    int tamLista;
};

template <typename T>
void ListaE_Inicializar(TLista<T> &lista){
    lista.elementoInicial = nullptr;
    lista.tamLista = 0;
}

//Insere um novo elemento na lista, considerado o inicio da cadeia.
template <typename T>
bool ListaE_InserirInicio(TLista<T> &lista, T data){
    TElemento<T> *novoElemento = new TElemento<T>;
    if(novoElemento == nullptr){
        return false;               //Caso nao tenha sido possivel alocar memoria para um novo elemento.
    }
    novoElemento->data = data;
    novoElemento->proximoElemento = lista.elementoInicial;
    lista.elementoInicial = novoElemento;
    lista.tamLista++;
    return true;
}

//Insere um novo elemento na posiçao n da lista
template<typename T>
bool ListaE_InserirEm(TLista<T> &lista, T data, int index){
    int _index = 0;
    TElemento<T> *novoElemento = new TElemento<T>;
    TElemento<T> *elementoAtual = lista.elementoInicial;
    if(novoElemento == nullptr || index < 0){
        return false;               //Caso nao tenha sido possivel alocar memoria para um novo elemento.
    }
    novoElemento->data = data;
    if(index == 0 || lista.elementoInicial == nullptr){
        novoElemento->proximoElemento = lista.elementoInicial;
        lista.elementoInicial = novoElemento;
    }else{
        while(elementoAtual->proximoElemento != nullptr && _index != index-1){
            elementoAtual = elementoAtual->proximoElemento;
            _index++;
        }
        novoElemento->proximoElemento = elementoAtual->proximoElemento;
        elementoAtual->proximoElemento = novoElemento;
    }
    return true;
}

//Insere um novo elemento no fim da lista, considerado o final da cadeia
template <typename T>
bool ListaE_InserirFim(TLista<T> &lista, T data){
    TElemento<T> *novoElemento = new TElemento<T>;
    TElemento<T> *elementoAtual = lista.elementoInicial;
    if(novoElemento == nullptr){
        return false;               //Caso nao tenha sido possivel alocar memoria para um novo elemento.
    }
    novoElemento->proximoElemento = nullptr;
    novoElemento->data = data;
    if(lista.elementoInicial == nullptr){
        novoElemento->proximoElemento = lista.elementoInicial; //novoElemento->proximo = null
        lista.elementoInicial = novoElemento;
    }else{
        while(elementoAtual->proximoElemento){
            elementoAtual = elementoAtual->proximoElemento;
        }
        elementoAtual->proximoElemento = novoElemento;
    }
    lista.tamLista++;
    return true;
}

//Remover elemento do inicio da lista, considerada o inicio da cadeia
template <typename T>
bool ListaE_RemoverInicio(TLista<T> &lista){
    TElemento<T> *elementoTemporario = lista.elementoInicial;
    if(elementoTemporario == nullptr){
        return false;       //Caso nao exista elemento na lista
    }else{
        lista.elementoInicial = elementoTemporario->proximoElemento;
        delete elementoTemporario;
    }
    lista.tamLista--;
    return true;
}

//Remover elemento na posição n da lista
template <typename T>
bool ListaE_RemoverEm(TLista<T> &lista, int indice){
    int _indice = 0;
    TElemento<T> *elementoAnterior = lista.elementoInicial;
    TElemento<T> *elementoAtual = lista.elementoInicial;
    if(elementoAnterior == nullptr || indice >= lista.tamLista){
        return false;               //Caso nao tenha sido possivel alocar memoria para um novo elemento.
    }else{
        if(indice == 0){
            lista.elementoInicial = elementoAnterior->proximoElemento;
            delete  elementoAtual;
        }else{
            while(elementoAtual->proximoElemento != nullptr && _indice < indice){
                elementoAnterior = elementoAtual;
                elementoAtual = elementoAtual->proximoElemento;
                _indice++;
            }
            elementoAnterior->proximoElemento = elementoAtual->proximoElemento;
            delete elementoAtual;
        }
    }
    lista.tamLista--;
    return true;
}

//Remover elemento na ultima posiçao da lista, considerado o ultimo elemento da cadeia;
template <typename T>
bool ListaE_RemoverFim(TLista<T> &lista){
    TElemento<T> *elementoAtual = lista.elementoInicial;
    TElemento<T> *elementoAnterior = lista.elementoInicial;
    if(elementoAtual == nullptr){
        return false;               //Caso nao tenha sido possivel alocar memoria para um novo elemento.
    }else{
        if(elementoAtual->proximoElemento == nullptr){      //Caso o primeiro elemento seja o unico elemento, é preciso
            delete lista.elementoInicial;                   //Nullificar o elemento inicial da lista
            lista.elementoInicial = nullptr;
        }
        else{
            while(elementoAtual->proximoElemento != nullptr){
                elementoAnterior = elementoAtual;
                elementoAtual = elementoAtual->proximoElemento;
            }
            elementoAnterior->proximoElemento = nullptr;
            delete elementoAtual;
        }
    }
    lista.tamLista--;
    return true;
}
#endif // LISTAENCADEADA_H
