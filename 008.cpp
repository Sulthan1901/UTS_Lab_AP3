#include <iostream>
using namespace std;
int main()
{
    cout<<"Masukkan nomor rekening anda : ";          
    int validasi,valid,validasi2,valid2;    
    long long norek,mods, dive;             
    cin>>norek;                             
    mods=100;                               
    dive=10;                                
    validasi=0;
    do
    {
        valid= (((norek%mods)/ dive)*2);    
        if (valid>=10|| valid <0)           
            {
                int angka_1, angka_2;
                angka_1= valid % 10;
                angka_2= valid / 10;
                valid = angka_1+angka_2;
            } 
            else
            {
                valid= valid;

            }
        validasi=validasi +valid;          
        mods*=100;                          
    } while ((mods<=10000000000000000)||(dive<=1000000000000000)); 

    mods=10;
    dive=1;
    validasi2=0; 
    do              
    {
        valid2= ((norek%mods)/ dive); 
        validasi2=validasi2+valid2;     
        mods*=100;                      
        dive*=100;
    } while ((mods<=1000000000000000)||(dive<=100000000000000)); 

    int valtol= validasi+validasi2; 

    string vld;     
    if ((((norek%10000000000000000)/1000000000000000)==5)&&(valtol% 10== 0))    
    {
        vld="MASTERCARD";
    }
    else if((((norek%10000000000000000)/1000000000000000)==4)&&(valtol% 10==0))
    {
        vld="VISA";
    }
    else
    {
        vld="Nomor rekening idak valid";
    }
    cout<<"Nomor kartu anda :"<< norek<<endl; 
    cout<<"Tipe kartu anda adalah :"<< vld <<endl;
    cout<<"checksum: "<<valtol<<endl;

    return 0;

}