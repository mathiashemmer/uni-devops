#ifndef LISTA_H
#define LISTA_H

template<typename T, int TAM>
struct Lista{
    T elementos[TAM];
    int tamanhoLista;
};

//Inicializa a lista, zerando seu tamanho inicial e garantindo espaço suficiente de memória
template<typename T, int TAM>
bool Lista_Inicializar(Lista<T, TAM> &playlist){
    playlist.tamanhoLista = 0;
    return true;
}

//Insere um elemento no inicio da lista, considerado o começo da corrente, ou primeiro índice do
template<typename T, int TAM>
bool Lista_InserirInicio(Lista<T, TAM> &playlist, T elemento){
    if(playlist.tamanhoLista >= TAM-1){
        return false;
    }else{
        for(int i = playlist.tamanhoLista; i >= 0; i--){
            playlist.elementos[i+1] = playlist.elementos[i];
        }
        playlist.elementos[0] = elemento;
        playlist.tamanhoLista++;
        return true;
    }
}

//Insere um elemento no fim da lista, considerado o tamanho atual da lista + 1
template<typename T, int TAM>
bool Lista_InserirFim(Lista<T, TAM> &playlist, T elemento){
    if(playlist.tamanhoLista >=  TAM-1){
        return false;
    }else{
        playlist.elementos[playlist.tamanhoLista] = elemento;
        playlist.tamanhoLista++;
        return true;
    }
}

//Insere um elemento em posição n.
template<typename T, int TAM>
bool Lista_InserirEm(Lista<T, TAM> &playlist, T elemento, int index){
    if(playlist.tamanhoLista >= TAM-1){
        return false;
    }else{
        if(index > playlist.tamanhoLista){
            index = playlist.tamanhoLista;
        }
        for(int i = playlist.tamanhoLista-1; i >= index; i--){
            playlist.elementos[i+1] = playlist.elementos[i];
        }
        playlist.elementos[index] = elemento;
        playlist.tamanhoLista++;
        return true;
    }
}

//Remove o primeiro elemento da lista, considerado o primeiro elemento da cadeia.
template<typename T, int TAM>
bool Lista_RemoveInicio(Lista<T, TAM> &playlist){
    if(playlist.tamanhoLista <= 0){
        return false;
    }else{
        for(int i = 0; i < playlist.tamanhoLista-1; i++){
            playlist.elementos[i] = playlist.elementos[i+1];
        }
        playlist.tamanhoLista--;
        return true;
    }
}

//Remove um elemento no final da cadeia
template<typename T, int TAM>
bool Lista_RemoveFim(Lista<T, TAM> &playlist){
    if(playlist.tamanhoLista <= 0){
        return false;
    }else{
        playlist.tamanhoLista--;
    }
    return true;
}

//Remove um elemento na posição n na lista, caso exceda o tamanho da lista, é removido do final
template<typename T, int TAM>
bool Lista_RemoveEm(Lista<T, TAM> &playlist, int index){
    if(playlist.tamanhoLista >= TAM-1){
        return false;
    }else{
        if(index > playlist.tamanhoLista){
            index = playlist.tamanhoLista;
        }
        for(int i = index; i < playlist.tamanhoLista-1; i++){
            playlist.elementos[i] = playlist.elementos[i+1];
        }
        playlist.tamanhoLista--;
        return true;
    }
}
#endif // LISTA_H
