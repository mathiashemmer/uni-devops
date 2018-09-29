#ifndef LISTADUPLAMENTEENCADEADA_H
#define LISTADUPLAMENTEENCADEADA_H

template<typename T>
struct TElementoDE{
    TElementoDE<T> *elementoAnterior;
    TElementoDE<T> *elementoProximo;
    T data;
};
template<typename T>
struct TListaDE{
    TElementoDE<T> *inicio;
};
template<typename T>
void ListaDE_Inicializar(TListaDE<T> &listaDE){
    listaDE.inicio = nullptr;
}

template<typename T>
TElementoDE<T>* NovoElemento(T data){
    TElementoDE<T> *novoElemento = new TElementoDE<T>;
    if(novoElemento == nullptr){
        return nullptr;
    }
    novoElemento->data = data;
    novoElemento->elementoAnterior  = nullptr;
    novoElemento->elementoProximo   = nullptr;
    return novoElemento;
}

template<typename T>
bool ListaDE_InserirInicio(TListaDE<T> &listaDE, T data){
    TElementoDE<T> *novoElemento = NovoElemento(data);
    if(novoElemento == nullptr){
        return false;
    }
    if(listaDE.inicio == nullptr){
        listaDE.inicio = novoElemento;
    }else{
        novoElemento->elementoProximo = listaDE.inicio;
        listaDE.inicio->elementoAnterior = novoElemento;
        listaDE.inicio = novoElemento;
    }
    return true;
}

template<typename T>
bool ListaDE_InserirFim(TListaDE<T> &listaDE, T data){
    TElementoDE<T> *novoElemento    = NovoElemento(data);
    TElementoDE<T> *elementoAtual   = listaDE.inicio;
    if(novoElemento == nullptr){
        return false;
    }
    if(listaDE.inicio == nullptr){
        listaDE.inicio = novoElemento;
    }else{
        while(elementoAtual->elementoProximo != nullptr){
            elementoAtual = elementoAtual->elementoProximo;
        }
        novoElemento->elementoAnterior = elementoAtual;
        elementoAtual->elementoProximo = novoElemento;
    }
    return true;
}

template<typename T>
bool ListaDE_InserirEm(TListaDE<T> &listaDE, T data, int indice){
    int _indice = 0;
    TElementoDE<T> *novoElemento    = NovoElemento(data);
    TElementoDE<T> *elementoAtual   = listaDE.inicio;
    if(novoElemento == nullptr){
        return false;
    }

    if(indice == 0 || listaDE.inicio == nullptr){
        novoElemento->elementoProximo = listaDE.inicio;
        listaDE.inicio = novoElemento;
        if(novoElemento->elementoProximo != nullptr){
            novoElemento->elementoProximo->elementoAnterior = novoElemento;
        }
    }else{
        while(_indice < indice-1 && elementoAtual->elementoProximo != nullptr){
            elementoAtual = elementoAtual->elementoProximo;
            _indice++;
        }if(elementoAtual != nullptr){
            novoElemento->elementoProximo = elementoAtual->elementoProximo;
            novoElemento->elementoAnterior = elementoAtual;
            elementoAtual->elementoProximo = novoElemento;
            TElementoDE<T> *temp = novoElemento->elementoProximo;
            if(temp != nullptr){
                temp->elementoAnterior = novoElemento;
            }
        }
    }
    return true;
}

template<typename T>
bool ListaDE_RemoverInicio(TListaDE<T> &listaDE){
    TElementoDE<T> *elementoADeletar = listaDE.inicio;
    if(elementoADeletar == nullptr){
        return false;
    }
    listaDE.inicio = elementoADeletar->elementoProximo;
    delete  elementoADeletar;
    if(listaDE.inicio != nullptr){
        listaDE.inicio->elementoAnterior = nullptr;
    }
    return true;
}

template<typename T>
bool ListaDE_RemoverFim(TListaDE<T> &listaDE){
    if(listaDE.inicio == nullptr){
        return false;
    }
    TElementoDE<T> *elementoADeletar = listaDE.inicio;
    while(elementoADeletar->elementoProximo != nullptr){
        elementoADeletar = elementoADeletar->elementoProximo;
    }
    if(elementoADeletar->elementoAnterior != nullptr){
        elementoADeletar->elementoAnterior->elementoProximo = nullptr;
    }
    delete elementoADeletar;
}

template<typename T>
bool ListaDE_RemoverEm(TListaDE<T> &listaDE, int indice){
    int _indice = 0;
    TElementoDE<T> *elementoAtual   = listaDE.inicio;
    TElementoDE<T> *elementoAnterior   = listaDE.inicio;
    if(elementoAtual == nullptr){
        return false;
    }
    while(_indice < indice-1 && elementoAtual->elementoProximo != nullptr){
        elementoAnterior = elementoAtual;
        elementoAtual = elementoAtual->elementoProximo;
        _indice++;
    }
    elementoAnterior->elementoProximo = elementoAtual->elementoProximo;
    if(elementoAtual->elementoProximo != nullptr){
        elementoAtual = elementoAtual->elementoProximo;
        elementoAtual->elementoAnterior = elementoAnterior;
    }
    delete elementoAnterior->elementoProximo;
    return true;
}

// Implementar:
//Remover
// -- EM

#endif // LISTADUPLAMENTEENCADEADA_H
