#define BUILDING_NODE_EXTENSION
#include <node.h>

#include <iostream>
#include <windows.h>

using namespace v8;

extern "C" __declspec (dllexport) double calcu_max(double* a, double* b);

Handle<Value> Max(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 2) {
    ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
    return scope.Close(Undefined());
  }

  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    ThrowException(Exception::TypeError(String::New("Wrong arguments")));
    return scope.Close(Undefined());
  }

  HINSTANCE hDLL;
//  hDLL=LoadLibrary("maxdllc.dll");//���ض�̬���ӿ�dlldemo.dll�ļ���
  hDLL=LoadLibrary("maxdllf.dll");//���ض�̬���ӿ�dlldemo.dll�ļ���
 // if(hDLL)
//	return scope.Close(String::New("load dll sucessfully!"));

  //typedef double(*pMax)(double a,double b);//����ָ��
  typedef double(*pMax)(double* a,double* b);//����ָ��
  pMax Max=NULL;
  Max=(pMax)GetProcAddress(hDLL,"calcu_max");
  
  if (Max) 
  {	
//     double A=Max(args[0]->NumberValue(),args[1]->NumberValue());
     double n1=	args[0]->NumberValue();
     double n2=	args[1]->NumberValue();
     double A=Max(&n1,&n2);
     
    //cout<<"�ȽϵĽ��Ϊ"<<A;
    Local<Number> num = Number::New(A);
    return scope.Close(num);
  }
  //Local<Number> num = Number::New(args[0]->NumberValue() +   args[1]->NumberValue());
  Local<Number> num = Number::New(123);
  return scope.Close(num);
}

void Init(Handle<Object> target) 
{
  target->Set(String::NewSymbol("max"),FunctionTemplate::New(Max)->GetFunction()); 
}

NODE_MODULE(max_addon, Init)