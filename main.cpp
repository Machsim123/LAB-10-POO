#include <assert.h>
#include <iostream>
#include <string>

using namespace std;

template <typename X, typename Y>
class pereche
{
    X elem1; ///unde X ar fi NC?
    Y elem2;
public:
    pereche(const X &e1, const Y &e2)
    {
     elem1=e1;
     elem2=e2;
    }
 friend ostream& operator<<(ostream &d,const pereche &x)
 {
    d<<x.elem1<<" si " << x.elem2<<endl;
    return d;
 }
};

template <typename T>
class vector
{ int dim;
  T* buf;
  public:
     vector();
     vector(int , T*);
     vector(const vector&);
     vector & operator=(const vector &);
     ~vector();
	 T& operator[](int i) const;
     int getDim() const;

	 friend ostream & operator << (ostream & dev,  vector & v)
     {
	    dev << "Vector:" <<endl;
	    dev << "Nr Elem:" << v.dim << endl;
	    if (v.buf!=NULL)
	    for(int i = 0; i < v.dim; i++) {
		   dev << v.buf[i];//am nevoie de op<< pt T
		   if(i < v.dim-1)
		    	dev << ",   ";
		   else
		    	dev << "." << endl;
		}
        dev<<endl;
	    return dev;
     }
     friend bool operator==( const vector<T>& v1, const vector<T>& v2)
     {
         if(v1.getDim() != v2.getDim())
            return 0;
         for(int i=0; i<v1.getDim(); i++)
            if(v1[i]!=v2[i])
                return 0;

         return 1;
     }

     friend bool operator!=( const vector<T>& v1, const vector<T>& v2)
     {
         return (!(v1==v2));
     }

     T* GetBuff()
     {
         return this->buf;
     }

     void addElem(const T& t)
     {
        if(this->getDim()==0)
            exit(1);

        T* bu= new T[this->getDim()*2];
        vector<T> vec(this->getDim()*2,bu);
        for(int i=0; i<vec.getDim(); i+=2)
            vec[i]=(*this)[i/2];
        for(int i=1; i<vec.getDim(); i+=2)
            vec[i]=t;
        *this=vec;
     }
};

template <typename T>
vector<T>::vector( ){
	dim=0;
	buf=NULL;
}

template <typename T>
vector<T>::vector(int d, T*b){
       dim=d;
       if (b==NULL) buf = NULL;
	   else{
	      buf=new T[dim]; //constr fara param in T
          for (int i=0;i<dim;i++)
            buf[i]=b[i]; //op= in T
        }
     }


template <typename T>
vector<T>::vector(const vector<T>& v){
       dim=v.dim;
       if (v.buf==NULL) buf=NULL;
       else{
	      buf=new T[dim]; //constr fara param in T
          for (int i=0;i<dim;i++)
             buf[i]=v.buf[i]; //op= in T
        }
	 }


template <typename T>
vector<T>::~vector(){
        delete [] buf; //destr in T
}

template <typename T>
vector<T>&  vector<T>::operator=(const vector &v){
       dim=v.dim;
       if (buf!=NULL) delete [] buf; //destr in T
       if (v.buf==NULL) buf=NULL;
       else{
	      buf=new T[dim]; //constr fara param in T
          for (int i=0;i<dim;i++)
             buf[i]=v.buf[i]; //op= in T
		}
        return *this;
}

template <typename T>
T& vector<T>::operator[](int i) const{
      assert ((i>-1 && i<dim));
	  return buf[i];  //constr de copiere in T
}

template <typename T>
int vector<T>::getDim() const{
   return dim;
}

class complex
{ double re,im;
public: complex(double r=0,double i=0):re(r),im(i){
        }

        friend ostream& operator<<(ostream &d,complex x){

            d<<x.re<<" j"<<x.im;
            return d;
        }
        friend bool operator==( const complex& c1, const complex& c2)
        {
            if(c1.re==c2.re && c1.im==c2.im) return 1;
                else return 0;
        }
        friend bool operator!=( const complex& c1, const complex& c2)
        {
            return (!(c1==c2));
        }
};



int main()
{
	 /*

	 complex *b=new complex[2];
	 b[0]=complex(1,2);
     b[1]=complex(2,2);
	 vector<complex> v(2,b);
     ///cout<<v;

	 ///cout<<v[0];
	 ///cout<<endl<<endl;

	 v[1]=complex(5,5);
     ///cout<<v;

     vector<complex> v1(v);
     cout<<v1;

     v=v1;
     cout<<v;
     ///cout<<(v1!=v);
     v.addElem(b[0]);
     cout<<v;


     */


     /*

     string* x=new string[2];
     x[0]=string("sunt string");
     x[1]=string("eu nu!");
     vector<string> vect(2,x);
     ///cout<<vect;

     ///cout<<vect[0];
     ///cout<<endl<<endl;
     ///cout<<vect[1];
     ///cout<<endl<<endl;

     vect[1]=string("nu sunt string...");
     ///cout<<vect;

     vector<string> vect12(vect);
     ///cout<<vect12;
     vect=vect12;
     cout<<vect;
     vect12[1]=string("oh nu!");
     ///cout<<(vect==vect12);
     cout<<vect12;
     vect12.addElem("dada");
     cout<<vect12;


     */
     /*

     double* y=new double[2];
     y[0]=1.234;
     y[1]=0.987904313;
     vector<double> vdo(2,y);
     cout<<vdo;
     ///cout<<vdo[0];
     ///cout<<endl;
     ///cout<<vdo[1];

     ///cout<<endl;
     vdo[1]=double(32121.12);
     cout<<vdo;
     vector<double>vdoc(vdo);
     cout<<vdoc;
     vdo=vdoc;
     vdo.addElem(2.02);
     cout<<vdo;
     ///cout<<vdo;

     ///cout<<(vdo!=vdoc);

     */


     string x="Alex Alex";
     int nota=2;

     pereche<string, int> p1(x,nota);
     x=string("Matei Matei");
     nota=4;
     pereche<string, int> p2(x,nota);

     vector<pereche<string, int>> vectoras(1,p1);
    // vectoras.addElem(p2);
     cout<<vectoras;

     return 0;
}
