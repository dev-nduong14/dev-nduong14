#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct ds{
	int tuoi;
	int diem;
	char name[100];
	struct ds *next;
};
typedef struct ds ds;
ds *taosvmoi(char ten[],int t ,int diemtb){
	ds *svmoi = (ds*)malloc(sizeof(ds));
	svmoi->tuoi = t;
	strcpy(svmoi->name,ten);
	svmoi->diem = diemtb;
	svmoi->next = NULL;
	return svmoi;
}
void themvaocuoi(ds **head,char ten[],int t ,int diemtb){
	ds* svmoi = taosvmoi(ten,t,diemtb);
	if(*head == NULL){
		*head = svmoi; return;
	}
	ds* k = *head;
	while(k->next != NULL){
		k = k->next; 
	}
	k->next = svmoi;
	
}
void themvaodau(ds **head,char ten[],int t ,int diemtb){
	ds *svmoi = taosvmoi(ten,t,diemtb);
	svmoi->next = (*head);
	*head = svmoi;
}
int size(ds *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void themvaogiua(ds **head, char ten[], int t, int diemtb, int k) {
    int n = size(*head);
    if (k < 1 || k > n + 1) {
        printf("Vi tri chen khong hop le.\n");
        return;
    }
    if (k == 1) {
        themvaodau(head, ten, t, diemtb);
    } 
    else if (k == n + 1) {
        themvaocuoi(head, ten, t, diemtb);
    } 
    else {
        ds *p = *head;
        for (int i = 1; i < k - 1; i++) {
            p = p->next;
        }
        ds *newsv = taosvmoi(ten, t, diemtb);
        newsv->next = p->next;
        p->next = newsv;
    }
}

void nhap(ds **head){
	        int tuoi;
	        int diem;
	        char name[100];
	        getchar();
		   	printf("Nhap ten sinh vien: \n");gets(name);
		   	printf("Nhap tuoi cua hoc sinh : \n");scanf("%d",&tuoi);
		   	printf("Nhap diem cua sinh vien : \n");scanf("%d",&diem);
		   	themvaocuoi(head,name,tuoi,diem);		   	
}
void duyet(ds *head){
	while(head != NULL){
		printf("%s \t %d \t %d\n",head->name,head->tuoi,head->diem);//in ra gia tri can in;
		head = head->next;// gan vi tri tiep theo vao gia tri day neeu gap null thi out 
	}
}
int main(){
	ds *head = NULL;
	
	int n;
	printf("Nhap so luong sinh vien.");
	scanf("%d",&n);
	while(1){
		printf("\n------------------\n");
		printf("\n    QUAN LY SINH VIEN   \n");
		printf("1.Nhap sinh vien.\n");
		printf("2.In ra thong tin sinh vien.\n");
		printf("3.Them sinh vien vao cuoi danh sach.\n");
		printf("4.Them sinh vien vao dau danh sach.\n");
		printf("5.Them sinh vien vao giua.\n");
		//printf("6.Xoa sinh vien khoa danh sach.\n");
		//printf("7.Tim kiem sinh vien.\n");
		printf("0.Thoat.\n");
		printf("\n-------------------\n");
		int lc;
		printf("\nYeu cau nhieu lam: ");
		scanf("%d",&lc);
		if(lc == 1){
		   for(int i = 0 ; i< n;i++){
		   	nhap(&head);
		   	//getchar();
		   }
		}
		if(lc == 2){
			printf("Ten \t Tuoi \t Diem\n");
			
				duyet(head);
		}
		if(lc == 3){
			nhap(&head);
		}
		if(lc == 4){
			int newtuoi;
			char newname[100];
			int newdiem;
			getchar();
			printf("Nhap ten can them vao dau danh sach: \n");gets(newname);
			printf("Nhap tuoi cua sinh vien can them : \n");scanf("%d",&newtuoi);
			printf("Nhap diem cua sinh vien can them: \n");scanf("%d",&newdiem);
			themvaodau(&head,newname,newtuoi,newdiem);
		}
	    else if(lc == 5){
	    	int newtuoi1;
			char newname1[100];
			int newdiem1;
			int k ;
			printf("Nhap vi tri can them: ");
			scanf("%d",&k);
			getchar();
			printf("Nhap ten can them vao  danh sach: \n");gets(newname1);
			printf("Nhap tuoi cua sinh vien can them : \n");scanf("%d",&newtuoi1);
			printf("Nhap diem cua sinh vien can them: \n");scanf("%d",&newdiem1);
	    	themvaogiua(&head,newname1,newtuoi1,newdiem1,k);
		}
		if(lc == 0){
			break;
		}		
	}	
}


