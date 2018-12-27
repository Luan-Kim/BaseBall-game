#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_NUM 4

int arr_include(int * arr, int len, int r){
	int i;
	for (i = 0; i < len; i++)
	{
		if (arr[i] == r)
		{
			return 1;
		}
	}
	return 0;
}

int is_duplicated(int *arr, int len)
{
	int i, j;
	for(i = 0; i < len - 1; i++){	
		for(j = i + 1; j < len; j++){
			if(arr[i] == arr [j]){
				printf("���ڴ� ���ġ �ʰ� �ֽ��ϴ�. ���Է� ���ּ���.");
				return 1;
			}	
		}
	}
	return 0;
}

int main()
{
    srand(time(NULL));
    int i = 0, j = 0;
    int count = 0;
    int strike = 0, ball = 0;
    int random[ARR_NUM];
   
    
    for(i=0; i < ARR_NUM; i++)
    {
    	random[ARR_NUM] = -1;
	}

    for (i = 0; i < ARR_NUM; i++)
    {
        int r = rand() % 10;
		
        while(arr_include(random, ARR_NUM, r))
        {
        	r = rand() % 10;
		}
		random[i] = r;
    }

    int user[ARR_NUM];

    while (1)
    {
        count++;
        
        do{
        	printf("���� %d���� �Է����ּ��� : ", ARR_NUM);
       	 	for(i = 0; i < ARR_NUM; i++){
        		scanf("%d", &user[i]);
        	}
        	
		} while (is_duplicated(user, ARR_NUM));

        strike = 0;
        ball = 0;
        for (i = 0; i < ARR_NUM; i++)
        {
            for (j = 0; j < ARR_NUM; j++)
            {
                if (random[i] == user[j])
                {
                    if (i == j)
                    {
                        strike++;
                    }
                    else
                    {
                        ball++;
                    }
                }
            }
        }
        if (strike == ARR_NUM)
        {
            printf("%d������������ϴ�!!\n", count);
            return 0;
        }
        printf("��Ʈ����ũ : %d, �� : %d\n", strike, ball);
    }
}
