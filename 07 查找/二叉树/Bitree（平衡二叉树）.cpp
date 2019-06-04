//ƽ������������߳�ΪAVL��
#include<iostream>

using namespace std;

typedef int status;

#define true 1
#define false 0

#define LH +1   //���
#define EH 0     //�ȸ�
#define RH -1     //�Ҹ�


//����������ṹ����
typedef struct Bitnode
{
	int data;
	int bf;    //�������ƽ������
	struct Bitnode *left,*right;
}Bitnode,*Bitree;


   //����
void R_rotate(Bitree *p);
void L_rotate(Bitree *p);
void Leftbalance(Bitree *T);
void Rightbalance(Bitree *T);
status Insertavl(Bitree *T,int e,status *taller);
void Createavl(Bitree *T,int a[],int n);
void Showbst(Bitree T);       //����������������
   

//fָ��T��˫�ף���Tָ����ڵ�ʱ�����f�ĳ�ʼ����ֵΪNull
//���ҳɹ���ָ��pָ�������Ԫ�صĽ�㣬����TRUE
//����ʧ�ܣ�Pָ�����·���Ϸ��ʵ����һ��Ԫ�أ�����false
Bitree Searchavl(Bitree T,int key)
{
	if (!T) 
		return NULL;

    //������  
    if (key==T->data)
        return T;
    else if (key<T->data)
    {
        //��������������  
        return Searchavl(T->left,key);
    }
    else
    {
        //��������������  
        return  Searchavl(T->right,key);
    }
}


//����pΪ���Ķ�����������������������֮��pָ���µ������ڵ�
//����ת֮ǰ���������ĸ��ڵ�
void R_rotate(Bitree *p)
{
	Bitree L;
	L=(*p)->left;
	(*p)->left=L->right;
	L->right=*p;
	*p=L;
}

//����pΪ���Ķ�����������������������֮��pָ���µ������ڵ�
//����ת֮ǰ���������ĸ��ڵ�
void L_rotate(Bitree *p)
{
	Bitree R;
	R=(*p)->right;
	(*p)->right=R->left;
	R->left=*p;
	*p=R;
}
//����TΪ���Ķ���������������ƽ�⴦��
//����֮��Tָ���µ������ڵ�
void Leftbalance(Bitree *T)
{
	Bitree L,Lr;
	L=(*T)->left;  //Lָ��T�������������
	switch(L->bf)
	{
		//���T��������ƽ��ȣ�������Ӧ�Ĵ���
	case LH:  //�½ڵ������T�����ӵ��������ϣ�Ҫ������������
		(*T)->bf=L->bf=EH;
		R_rotate(T);
		break;
    case RH:    //�½ڵ������T�����ӵ��������ϣ�Ҫ������������
		Lr=L->right;  //Lrָ��T�����ӵ���������
		switch(Lr->bf)
		{
		case LH: 
			(*T)->bf=RH;
			L->bf=EH;
			break;
		case EH:
			(*T)->bf=L->bf=RH;
			break;
		case RH:
			(*T)->bf=EH;
			L->bf=LH;
			break;
		}
		Lr->bf=EH;
		L_rotate(&(*T)->left);
		R_rotate(T);
	}
}


//T ���ұ߸ߣ���ƽ�⣬ʹ��ƽ�⣬����ת������תǰ�ȼ��R->bf
//���ΪLH��RҪ�Ƚ�������ת��ʹT->rchild->bf��T->bfһ��
void Rightbalance(Bitree *T)
{
    Bitree R,Rl;
    R = (*T)->right;
    Rl = R->left;
    switch(R->bf)
    {
        case RH:
            R->bf = (*T)->bf = EH;
            L_rotate(T);
            break;
        case LH:
            switch(R->bf)
            {
                case LH:
                    R->bf = RH;
                    (*T)->bf = EH;
                    break;
                case EH:
                    R->bf = (*T)->bf = EH;
                    break;
                case RH:
                    R->bf = EH;
                    (*T)->bf = LH;
                    break;
            }
            Rl->bf = EH;
            R_rotate(&R);
            L_rotate(T);
            break;
    }
}

//����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬�����һ��
//����Ԫ��Ϊe���½ڵ㲢����1�����򷵻�0
//�������ʹ�ö�����ʧȥƽ�⣬����ƽ����ת����������taller��ӳT�������
status Insertavl(Bitree *T,int e,status *taller)
{
	if(!*T)
	{
		//�����½ڵ㣬�����ߣ�tallerΪtrue
		*T=(Bitree)malloc(sizeof(Bitnode));
		(*T)->data=e;
		(*T)->left=(*T)->right=NULL;
		(*T)->bf=EH;
		*taller=true;
	}
	else
	{
		if(e==(*T)->data)
		{
			//���д��ں�e����ͬ�ؼ��ֵĽ�㽫���ٲ���
			*taller=false;
			return false;
		}
		if(e<(*T)->data)
		{
			//Ӧ������t���������н�������
			if(!Insertavl(&(*T)->left,e,taller))
				return false;
			if(*taller)
			{
				switch((*T)->bf)
				{
				case LH:
					Leftbalance(T);
					*taller=false;
					break;
				case EH:
					(*T)->bf=LH;
					*taller=true;
					break;
				case RH:
					(*T)->bf=EH;
					*taller=false;
					break;
				}
			}
		}
		else
		{
			if(!Insertavl(&(*T)->right,e,taller))
				return false;
			if(*taller)
			{
				switch((*T)->bf)
				{
				case LH:
					(*T)->bf=EH;
					*taller=false;
					break;
				case EH:
					(*T)->bf=RH;
					*taller=true;
					break;
				case RH:
					Rightbalance(T);
					*taller=false;
					break;
				}
			}
		}
	}
	return true;
}

void Createavl(Bitree *T,int a[],int n)
{
	int i;
	status taller;
	for(i=0;i<n;i++)
	{
		Insertavl(T,a[i],&taller);
	}
}


void Showbst(Bitree T)
{
	if(T)
	{
		Showbst(T->left);
		cout<<T->data<<" ";
		Showbst(T->right);
	}
}

int main()
{
	int a[]={62,88,58,47,35,73,51,99,37,93};

	Bitree T=NULL;
	status taller=0;

	//��������������
	Createavl(&T,a,10);
	cout<<"��������Ľ��Ϊ��"<<endl;
	Showbst(T);
	cout<<endl;


	//�ڶ����������в���56
	Insertavl(&T,56,&taller);
	cout<<"��������Ľ��Ϊ��"<<endl;
	Showbst(T);
	cout<<endl;


	int b=58;  //��Ҫ���ҵ�ֵ
	Bitree p=NULL;
	T=Searchavl(T,b);
	cout<<"���ҽ��Ϊ:\n"<<"ָ�룺"<<T<<endl
		<<"ָ���ֵΪ��"<<T->data<<endl;


	system("pause");
	return 0;
}