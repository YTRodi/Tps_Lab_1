
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this !=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    /**RETORNA LA el vagon**/
    Node* nodoRetorno = NULL;
    int len = ll_len(this);//getter del size.

    if(this!=NULL && nodeIndex>=0 && nodeIndex<len)
    {
        nodoRetorno = this->pFirstNode;//direccion de memoria del primer vagon

        while(nodeIndex>0)
        {
            nodoRetorno = nodoRetorno->pNextNode;//en nodoRetorno voy a tener la dire de memoria del siguiente.
            nodeIndex--;//voy descontando el indice
        }
    }
    return nodoRetorno;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    Node* newNode = NULL;
    Node* auxAnterior = NULL;
    Node* auxSiguiente = NULL;
    int contador = 1;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=len)
    {
        newNode = (Node*)malloc(sizeof(Node));

        if(newNode!=NULL)//quiere decir que hay memo para trabajar
        {
            //creamos nuevo nodo
            newNode->pElement = pElement;//si no hago esto, tengo basura
            newNode->pNextNode = NULL;//si no hago esto, tengo basura

            if(nodeIndex==0)
            {
                newNode->pNextNode = this->pFirstNode;
                this->pFirstNode = newNode;
            }
            else
            {
                auxAnterior = this->pFirstNode;
                auxSiguiente = auxAnterior->pNextNode;

                while(nodeIndex>contador)//sino se iba de rango si el indice era menos al contador.
                {
                    auxAnterior = auxSiguiente;
                    auxSiguiente = auxAnterior->pNextNode;
                    contador ++;
                }
                auxAnterior->pNextNode = newNode;
                newNode->pNextNode = auxSiguiente;







                //el anterior va a ser el firstNode. se le asigna y posiciona en el primero.
                /*
                anterior = this->firstNode//indistinta si es igual o no.
                siguiente = anterior->nextNode;
                -tengo guardado el anterior y el siguiente.

                iterar--
                anterior->nextnode = newNode;
                newNode->pNextNode = siguiente.
                ----------------------------------------------------
                anterior = siguiente;
                siguiente = anterior->PnextNode
                */
            }
            this->size++;//aumentamos el tamaño del linkedlist.
            returnAux = 0;

        }


    }


    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        //no tengo que crear una variable auxiliar y pasarla en vez de el this->size ??

        if(addNode(this,this->size,pElement)!=-1)
        {
            //this->size es al cantidad de nodos que tiene la linkedlist.
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado.
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    /**RETORNA LA CARGA**/
    void* returnAux = NULL;
    Node* auxNode = NULL;

    int len = ll_len(this);

    if(this!=NULL && index>=0 && index<len)
    {
        auxNode = getNode(this,index);//obtengo el nodo de la lista, nos retorna la carga.

        if(auxNode!=NULL)
        {
            return auxNode->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    Node* auxNode = NULL;

    if(this!=NULL && index>=0 && index<=len)
    {
        auxNode = getNode(this,index);

        if(auxNode!=NULL)
        {
            auxNode->pElement = pElement;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len = ll_len(this);
    Node* auxNode = NULL;//es el nodo a eliminar
    Node* auxAnterior = NULL;
    Node* auxSiguiente = NULL;

    if(this!=NULL && index>=0 && index<=len)
    {
        auxNode = getNode(this,index);//obtengo el nodo a eliminar

        if(auxNode!=NULL)
        {
            if(index == 0)
            {
                this->pFirstNode = auxNode->pNextNode;
                free(auxNode);
                returnAux = 0;
                this->size--;
            }
            else
            {
                /**VERIFICAR SI SE PUEDE HACER MEJOR.***/
                /*auxAnterior = this->pFirstNode;
                auxSiguiente = auxAnterior->pNextNode;*/

                auxAnterior = getNode(this,(index -1));//copio nodo previo al nodo a eliminar
                auxSiguiente = getNode(this,(index +1));//copio nodo siguiente al nodo a eliminar

                auxAnterior->pNextNode = auxSiguiente;//uno el nodo previo y el siguiente del eliminado

                free(auxNode);
                this->size--;

                returnAux = 0;
            }
        }
    }

    return returnAux;

}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;

        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;
    int len = ll_len(this);

    if(this!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            auxNode = getNode(this,i);

            if(auxNode->pElement == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(this->size>0)
        {
            returnAux = 0;
        }
        if(this->size==0)
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    //Node* auxNode = NULL;//es el nodo a insertar.

    if(this!=NULL && index>=0 && index<=len)
    {
        addNode(this,index,pElement);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* nodoRetornado = NULL;
    int len = ll_len(this);

    if(this!=NULL && index>=0 && index<len)
    {
        nodoRetornado = getNode(this,index);

        if(nodoRetornado!=NULL)
        {
            returnAux = nodoRetornado->pElement;
            ll_remove(this,index);
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        /**NOTA: ll_indexOf sino encuentra el elemento la función retorna (-1)**/

        if(ll_indexOf(this,pElement) == -1)
        {
            returnAux = 0;//si no encuentra al elementos
        }
        else
        {
            returnAux = 1;//si encuentra al elementos
        }

    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista2 (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len_this = ll_len(this);
    int len_this2 = ll_len(this2);
    //para ver si hay elementos o no, si difieren o no entre dos listas, me centro en el tamaño de cada lista.

    Node* auxNode = NULL;

    if(this!=NULL && this2!=NULL)
    {
        returnAux = 0;

        if(len_this >= len_this2)
        {
            for(int i=0; i<len_this2; i++) //tengo que recorrer this2 para saber si esta contenido en la lista(this).
            {
                auxNode = getNode(this,i);

                if(ll_contains(this2,auxNode->pElement)==1)
                {
                    returnAux = 1;
                }
            }//fin for
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;//lista a ser retornada con los elementos.
    int len = ll_len(this);
    Node* auxNode = NULL;

    if(this!=NULL && (from>=0 && from<=len) && (to>=from && to<=len))
    {
        cloneArray = ll_newLinkedList();//creo un nuevo linkedList.

        /**Ahora tengo que pasarle los elementos.***/

        if(cloneArray!=NULL)
        {
            /*tengo que recorrer el tamaño de la lista,
            para luego obtener el indice.*/

            for(int i=0; i<len; i++)
            {
                auxNode = getNode(this,i);//obtengo el nodo

                if(auxNode!=NULL)
                {
                    //Existe la nueva lista, pero no tiene un nodo.
                    //Si todo esta Okey, agrego y enlazo un nuevo nodo a la sub lista.
                    //le paso el linkedList que clone, el indice y por ultimo el elemento.

                    addNode(cloneArray,i,auxNode->pElement);
                }
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);

    if(this!=NULL)
    {
        cloneArray = ll_subList(this,0,len);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion
           criterio recibida como parametro.
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int len = ll_len(this);

    //creo auxiliares tipo void
    void* nodoAux;

    if(this!=NULL && pFunc!=NULL)
    {
        if(order == 0 || order == 1)
        {
            for(int i=0; i<len-1; i++)
            {
                for(int j=i+1; j<len; j++)
                {
                    if((pFunc(ll_get(this,i), ll_get(this,j))>0 && order == 1) ||
                        (pFunc(ll_get(this,i), ll_get(this,j))<0 && order == 0))
                    {
                        //SWAP.
                        nodoAux = ll_get(this,i);
                        ll_set(this,i, ll_get(this,j));
                        ll_set(this,j,nodoAux);
                        //ll_set = Inserta un elemento en el LinkedList, en el índice especificado.
                        //retorna un puntero al elemento que se encuentra en el índice especificado.
                        returnAux = 0;
                    }
                }
            }
        }
    }

    return returnAux;
}

