### int updateproduct(product *p);//제품 정보를 업데이트한다.
이름 수정, 정보 수정, 가격 수정, 수량 수정이 가능하다. 
> 2022.5.6

수정 할 것인지 아닌지 의견을 한번 더 물어보는 기능을 추가했다. 
> 2022.5.7

![Update Function](https://user-images.githubusercontent.com/103114649/167306019-e0271ead-4f44-4ae2-bc40-6120852ccfda.JPG)
Created by 장세창

### int deleteProduct(product *p)//제품의 정보를 삭제한다.
제품에 대한 정보를 삭제하는 function이다. 이름이 없거나 가격이 -1 이라면 제품이 삭제된 것으로 간주한다. 
> 2022.5.6

재고가 0이라면 삭제된 것으로 처리하도록 했다. 이는 동시에 물품을 품절 처리하기 위함이다. 
> 2022.5.7

![Delete Function](https://user-images.githubusercontent.com/103114649/167306038-7378ac59-4779-4f08-8557-903f9419e395.JPG)
Created by 장세창

### int selectMenu()//메뉴 선택 기능
메뉴를 선택하는 기능입니다. 
> 2022.5.6

![Select Menu Function](https://user-images.githubusercontent.com/103114649/167306336-030242e9-606b-4a3b-b9aa-b61a10f8255c.jpg)

Created by 장세창

### int updateproduct(product *p);//제품 정보를 업데이트한다.
이름 수정, 정보 수정, 가격 수정, 수량 수정이 가능하다. 
> 2022.5.6

수정 할 것인지 아닌지 의견을 한번 더 물어보는 기능을 추가했다. 
> 2022.5.7

![Update Function](https://user-images.githubusercontent.com/103114649/167306019-e0271ead-4f44-4ae2-bc40-6120852ccfda.JPG)
Created by 장세창

### int createproduct(product *p);//제품을 추가한다.
제품을 추가한다 (이름, 정보, 가격, 수량)
> 2022.5.6
> 함수 추가

![Create Function](https://github.com/JJangJo/miniproject/blob/main/screenshot/Create%20Function.JPG?raw=true)
Created by 조성준

### void listproduct(product p[],int count);//모든 프로덕트의 정보를 출력한다.
입력되어 있는 정보를 읽어오는 기능이다.
> 2022.5.6
> 함수 추가. 

![Read Function](https://raw.githubusercontent.com/JJangJo/miniproject/main/screenshot/Read%20Function.JPG)
Created by 조성준


### int readproduct(product p);//한가지의 프로덕트 정보를 출력한다.
어느 특정 정보를 자세히 (상품 정보 포함) 출력한다.
> 2022.5.6
> 함수 추가. 추후에 검색 기능이 구현되면 그것과 연관시켜 정보 출력 할 예정.

출력 예시(예상): 
>제품명: 미니 크로와상
>200원
>10개 남음
>
>제품 정보: 크로와상보다 작은 크로와상

Created by 조성준
