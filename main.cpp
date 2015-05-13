#include <QCoreApplication>
#include <iostream>

using namespace std;

class Legislador{
public:
    int id;
    bool bueno;
    Legislador *sig;

    Legislador(){
        id=0;
        bueno=true;
        sig=NULL;
    }

    Legislador(int id,bool bueno){
        this->id=id;
        this->bueno=bueno;
    }

};


class Leyes{
public:
    string descripcion;
    bool buena;
    Leyes *sig;

    Leyes(){

    }

    Leyes( string descripcion,bool buena){
        this->descripcion=descripcion;
        this->buena=buena;
    }
};

Legislador *inicio=NULL,*final=NULL;
Legislador *fbuenos=NULL,*fmalos=NULL,*ibuenos=NULL,*imalos=NULL;
Leyes *inicioLey=NULL,*finalLey=NULL;
int size=0;
int sizeley=0;
int sizebuenos=0;
int sizemalos=0;


bool miembro(int m){
 Legislador *actual=inicio;
 for(int i=0;i<size;i++){
      if(actual->id==m)
          return true;
      actual=actual->sig;
  }
  return false;
}


void insertar(int id,bool bueno){
    if(!miembro(id)){
        if(inicio==NULL){
            inicio=new Legislador(id,bueno);
            final=inicio;
            size++;
            return;
        }else{
            final->sig=new Legislador(id,bueno);
            final=final->sig;
            size++;
        }
     }
}


Legislador *getPos(int pos){
    if(pos>=0&&pos<size){
        if(pos==size-1)
            return final;
        else{
            Legislador *actual=inicio;
            for(int i=1;i<=pos;i++)
                 actual=actual->sig;
             return actual;
        }
    }
}


void eliminar(int pos){
    pos-=1;
    if(pos==size-2){
       Legislador *actual=getPos(pos);
       actual->sig=NULL;
       delete final;
       final=actual;
       size--;
     }else if(pos==-1){
       Legislador *actual=inicio;
       inicio=inicio->sig;
       delete actual;
       size--;
     }
     else if(pos>=0&&pos<size-1){
       Legislador *actual=getPos(pos);
       Legislador *act=actual->sig;
       actual->sig=act->sig;
       delete act;
       size--;
            }
}

bool existeLey(string d){
 Leyes *actual=inicioLey;
 for(int i=0;i<sizeley;i++){
      if(actual->descripcion==d)
          return true;
      actual=actual->sig;
  }
  return false;
}

void insertarLey(string descripcion,bool bueno){
    if(!existeLey(descripcion)){
        if(inicioLey==NULL){
            inicioLey=new Leyes(descripcion,bueno);
            finalLey=inicioLey;
            sizeley++;
            return;
        }else{
            finalLey->sig=new Leyes(descripcion,bueno);
            finalLey=finalLey->sig;
            sizeley++;
        }
     }
}

bool existeBueno(int id){
 Legislador *actual=ibuenos;
 for(int i=0;i<sizebuenos;i++){
      if(actual->id==id)
          return true;
      actual=actual->sig;
  }
  return false;
}

bool existeMalo(int id){
 Legislador *actual=imalos;
 for(int i=0;i<sizemalos;i++){
      if(actual->id==id)
          return true;
      actual=actual->sig;
  }
  return false;
}

void insertarBuenos(int id,bool bueno){
    if(!existeBueno(id)){
        if(ibuenos==NULL){
            ibuenos=new Legislador(id,bueno);
            fbuenos=ibuenos;
            sizebuenos++;
            return;
        }else{
            fbuenos->sig=new Legislador(id,bueno);
            fbuenos=fbuenos->sig;
            sizebuenos++;
        }
     }
}

void limpiarBuenos(){
    Legislador *actual=ibuenos;
    for(int i=0;i<sizebuenos;i++){
       if(i==0){
        delete ibuenos;
       }
       delete actual->sig;

    }
    sizebuenos=0;
}


void insertarMalos(int id,bool bueno){
    if(!existeMalo(id)){
        if(imalos==NULL){
            imalos=new Legislador(id,bueno);
            fmalos=imalos;
            sizemalos++;
            return;
        }else{
            fmalos->sig=new Legislador(id,bueno);
            fmalos=fmalos->sig;
            sizemalos++;
        }
     }
}

void limpiarMalos(){
    Legislador *actual=imalos;
    for(int i=0;i<sizemalos;i++){
       if(i==0){
        delete imalos;
       }
       delete actual->sig;
    }
    sizemalos=0;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    insertar(3,true);
    insertar(4,true);
    insertar(1,true);
    insertar(2,true);

    insertarBuenos(1,true);
    insertarBuenos(2,true);
    insertarMalos(3,false);


    bool b=false;
    string d="20ISV";
    string e="aumentoSalario";
    bool bu=true;
    insertarLey(d,b);
    insertarLey(e,bu);

    cout<<"Size: "<<sizebuenos<<endl;
    cout<<"Size2: "<<sizeley<<endl;

    Legislador *tmp2=inicio;
     for(int i=0;i<size;i++){
        cout<<"El id de los Legisladores : "<<tmp2->id<<endl;
        tmp2=tmp2->sig;
     }

    return a.exec();
}
