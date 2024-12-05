#include<stdio.h>
int main(){
	int choice,length=0,min2;
	int arr[100];
	do{
		printf("---------MENU----------\n");
		printf("1.Nhap so phan tu va gan gia tri\n");
		printf("2.In ra cac phan tu co trong mang\n");
		printf("3.Dem so luong cac so hoan hao co trong mang\n");
		printf("4.Tim gia tri nho thu hai trong mang\n");
		printf("5.Them mot tu ngau nhien co trong mang\n");
		printf("6.Xoa phan tu tai vi tri cu the\n");
		printf("7.Sap xep mang theo vi tri tang dan\n");
		printf("8.Tim kiem phan tu co trong mang hay khong\n");
		printf("9.Sap xep mang sao cho le dung truoc chan dung sau\n");
		printf("10.Kiem tra mang xem co phai mang tang dan hay khong\n");
		printf("11.Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d",&choice);
		switch(choice){
		case 1:{
			printf("Moi ban nhap do dai cua phan tu co trong mang: ");
			scanf("%d",&length);
			if(length>0){
				for(int i=0;i<length;i++){
					printf("arr[%d]= ",i);
					scanf("%d",&arr[i]);
				}
			} else {
				printf("Moi dai ka nhap lai do dai cua mang\n");
			}
			break;
		}
		case 2:{
			if(length>0){
				printf("cac phan tu co trong mang:\n");
				for(int i=0;i<length;i++){
					printf("arr[%d]= %d",i,arr[i]);
					printf("\n");
				}
			} else {
				printf("Moi dai ka nhap lai do dai cua mang\n");
			}
			break;
		}
		case 4: { 
                if (length > 1) {
                    int min = arr[0];
                    for (int i = 1; i < length; i++) {
                        if (arr[i] < min) {
                            min2 = min;
                            min = arr[i];
                        }  
					 for (int i = 1; i < length; i++){
					 	if (arr[i] > min && arr[i] < min2)
                            min2 = arr[i];
                        }
                    }
                        printf("so nho thu 1: %d\n", min);
                        printf("so nho thu 2: %d\n", min2);
                    } else {
                    printf("nhap it nhat co 2 phan tu.\n");
                }
                break;
            }
	
		case 5:{
			int posi,element;
			if (length>0){
				printf("Moi ban nhap gia tri can chen: ");
				scanf("%d",&element);
				do{
					printf("Moi ban nhap vi tri muon them: ");
					scanf("%d",&posi);
				} while(posi<0||posi>100);
				if(posi>=length){
					arr[posi]=element;
					length=posi+1;
				} else{
					length=length+1;
					for(int i=length;i>posi;i--){
						arr[i]=arr[i-1];
					}
					arr[posi]=element;
				}
				printf("mang sau khi them phan tu:\n");
				for(int i=0;i<length;i++){
					printf("%d",arr[i]);
					printf("\n");
				}
			}else{
				printf("Moi dai ka nhap lai do dai cua mang.\n");
			}
			
			break;
		}
		case 6:{
			int del;
			if(length>0){
				do{
					printf("Moi ban nhap vi tri muon xoa: ");
					scanf("%d",&del);
				}while(del<0||del>length-1);
				length=length-1;
				for(int i=del;i<length;i++){
					arr[i]=arr[i+1];
				}
				printf("Mang sau khi xoa: \n");
				for(int i=0;i<length;i++){
					printf("%d",arr[i]);
					printf("\n");
				}
			}else{
				printf("Moi dai ka nhap lai do dai cua mang.\n");
			}
			break;
		}
		case 7:{
			if(length>0){
				printf("Mang sau khi duoc sap xep: \n");
				for(int i=0;i<length-1;i++){
					for (int j=i+1;j<length;j++){
						if(arr[i]>arr[j]){
							int temp=arr[i];
							arr[i]=arr[j];
							arr[j]=temp;
						}
					}
				}
				for(int i=0;i<length;i++){
					printf("%d",arr[i]);
					printf("\n");
				}
			} else {
				printf("Moi ban nhap lai do dai cua mang: ");
			}
			break;
		}
		case 8:{
			if(length>0){
				int search;
				printf("Moi dai ka nhap phan tu can tim kiem: ");
				scanf("%d",&search);
				for(int i=0;i<length;i++){
					if(search==arr[i]){
						printf("Phan tu %d co trong mang",search);
						printf(" phan tu %d thi o vi tri %d trong mang",search,i);
						break;
					} else {
						printf("Phan tu ban tim kiem khong co trong mang\n");
						break;
					}	
				}
				
			}else{
				printf("Moi dai ka nhap lai do dai cua phan tu\n");
			}
			break;
		}
		case 9:{
			if(length>0){
				printf("Mang sau khi duoc sap xep: \n");
				for(int i=0;i<length-1;i++){
					for (int j=i+1;j<length;j++){
						if(arr[i]%2!=0 && arr[j]%2==0){
							int temp=arr[i];
							arr[i]=arr[j];
							arr[j]=temp;
						}
					}
				}
				for(int i=0;i<length;i++){
					printf("%d",arr[i]);
					printf("\n");
				}
			} else {
				printf("Moi ban nhap lai do dai cua mang: ");
			}
			break;
		}
		case 10: {
			if(length>1){
				for(int i=0;i<length-1;i++){
					for(int j=i+1;j<length;j++){
						if(arr[i]>arr[j]){
							printf("Mang sap xep tang dan\n");
							break;
						} 
					}
				} printf("Mang chua duoc sap xep\n");
			} else {
				printf("Moi ban nhap lai do dai cua mang\n");
			}
			break;
		}
		case 11:{
			printf("Thoat khoi chuong trinh.\n");
			break;
		}
		default:
			printf("Moi ban nhap lai");
	}

	}while(choice!=11);

	return 0;
}
