#include <stdio.h>
#include <math.h>
#include <string.h>

int borrow();
int total_cost();
int money_per_mount();
int work_out();
int currencyy();
int installment();
int stair_tax();
int tax_car();
int interest();

int main() {
  printf("ใส่เลข 1-9 เพื่อเลือกบริการ\n");
  printf("1 การกู้เงิน\n");
  printf("2 ลงทุนให้ได้กำไรมากที่สุด(TC)");
  printf("3 บริหารเงินเดือน\n");
  printf("4 คํานวณรายได้จากการทำงานล่วงเวลา\n");
  printf("5 แลกเปลี่ยนสกุลเงิน\n");
  printf("6 ผ่อน\n");
  printf("7 ภาษีบุคคล\n");
  printf("8 ภาษีรถยนตร์\n");
  printf("9 คิดดอกเบี้ยแบบทบต้น\n");
  int num;
  scanf("%d", &num);
  switch(num){
    case 1:
      borrow();
      break;
    
    case 2:
      total_cost();
      break;
    
    case 3:
      money_per_mount();
      break;

    case 4:
      work_out();
      break;
      
    case 5:
      currencyy();
      break;
    
    case 6:
      installment();
      break;
    
    case 7:
      stair_tax();
      break;
    
    case 8:
      tax_car();
      break;
    
    case 9:
      interest();
      break;
    
    default:
      printf("ทำรายการไม่ถูกต้อง\n");
  }
  return 0;
}

int borrow(){
  double money, max_money, func_top, func_low, dept, calfunc, cal_per, cal_dept, cal_bow, total;
  printf("กรุณากรอกข้อมูลตามลำดับ\n");
  printf("1.รายได้ หรือ เงินเดือน\n");
  printf("2.จำนวนผ่อนชำระหนี้สูงสุดที่แบกรับได้ต่อเงินเดือน\n");
  printf("3.อัตราส่วน ของเงินผ่อนชำระต่องวด เช่น 7000/1000000\n");
  printf("4.หนี้สินปัจจุบันที่ต้องชำระต่อเดือน\n");
  scanf("%lf %lf", &money, &max_money);
  printf("กรุณากรอกข้อมูลตามลำดับ\n");
  printf("1.เศษ\n");
  printf("2.ส่วน\n");
  scanf("%lf %lf %lf", &func_top, &func_low, &dept);
  calfunc = func_top/func_low;
  cal_per = max_money/money;
  cal_dept = max_money-dept;
  cal_bow = (money*cal_per)-dept;
  total = (cal_bow*func_low)/func_top;
  printf("ความสามารถในการกู้สูงสุดของคุณคือ %.2lf บาท\n", total);
  return 0;
}

int total_cost(){
  double demand,order_cost,holding_cost,price,promotion,qual;
  printf("กรุณากรอกข้อมูลตามลำดับ\n");
  printf("1.ความต้องการสินค้าต่อปี\n");
  printf("2.ค่าใช้จ่ายในการสั่งซื้อสินค้าต่อครั้ง\n");
  printf("3.ค่าใช้จ่ายในการเก็บสินค้าต่อชิ้น\n");
  printf("4.ราคาสินค้าต่อชิ้น\n");
  printf("5.ส่วนลดต่อชิ้น(ถ้ามี == 1, ไม่มี == 0)\n");
  scanf("%lf %lf %lf %lf %lf ", &demand, &order_cost, &holding_cost, &price, &promotion);
  double pro,qual_new,cal1,cal2,total_cost;
  if(promotion == 1){
    printf("กรุณากรอกข้อมูลตามลำดับ\n");
    printf("1.ส่วนลดราคาสินค้าต่อชิ้นเป็นร้อยละทศนิยม\n");
    printf("2.ปริมาณสินค้า\n");
    scanf("%lf %lf", &pro, &qual_new);
    cal1 = pro*price;
    cal2 = price-cal1;
    total_cost = (holding_cost*qual_new/2)+(order_cost*demand/qual_new)+(cal2*demand);
    printf("ค่าใช้จ่ายทั้งหมด %.2lf บาท\n",total_cost);
  }
  else{
    total_cost = ((holding_cost*qual)/2)+(order_cost*demand)/qual;
    printf("ควรสั่งสินค้า %.0lf ชิ้น และมีค่าใช้จ่ายทั้งหมด %.2lf บาท", qual, total_cost);
  }
  return 0;
}

int money_per_mount(){
  double you_money,dept,need,eat,cal_eat,keep,home,car,light,phone,value,cal;
  printf("โปรดกรอกข้อมูลตามลำดับ\n");
  printf("1.เงินเดือน\n");
  printf("2.หนี้สิน ไม่มี ==0\n");
  scanf("%lf %lf", &you_money, &dept);
  if(dept == 0){
    need = you_money*0.4;
    eat = you_money*0.4;
    double neat = eat;
    for(cal_eat=0 ; 30 < neat ; cal_eat++){
      neat = neat - 30;
    }
    keep = you_money*0.2;
    printf("คุณมีส่วนใช้จ่ายสิ่งที่จำเป็น %.2lf บาท ส่วนใช้จ่ายอาหาร %.2lf บาท/วัน ส่วนเงินเก็บ %.2lf บาท\n", need, cal_eat, keep);
    printf("โปรดกรอกค่าใช้จ่ายสิ่งที่จำเป็น/เดือน\n");
    printf("1.ค่าเช่าบ้าน หรือ ค่าเช่าหอ\n");
    printf("2.ค่าผ่อนรถ\n");
    printf("3.ค่าน้ำ-ค่าไฟ\n");
    printf("4.ค่าโทรศัพท์\n");
    printf("5.อื่นๆ\n");
    scanf("%lf %lf %lf %lf %lf",&home, &car, &light, &phone, &value);
    cal = need-home-car-light-phone-value;
    if(cal < 0){
      printf("คุณใช้จ่ายมากเกินไป %.2lf บาท โปรดใช้จ่ายอย่างประหยัด\n",cal*-1);
    }
    else{
      printf("คุณมีค่าใช้จ่ายสิ่งที่จำเป็นเหลืออยู่ %.2lf บาท\n",cal);
    }
  }
  else{
    need = you_money*0.4;
    eat = you_money*0.5;
    double neat = eat;
    for(cal_eat=0 ; 30 < neat ; cal_eat++){
      neat = neat - 30;
    }
    keep = you_money*0.1;
    printf("คุณมีส่วนใช้จ่ายสิ่งที่จำเป็น %.2lf บาท ส่วนใช้จ่ายอาหารรวมกับส่วนใช้หนี้ %.2lf บาท/วัน ส่วนเงินเก็บ %.2lf บาท\n", need, cal_eat, keep);
    printf("โปรดกรอกค่าใช้จ่ายสิ่งที่จำเป็น/เดือน\n");
    printf("1.ค่าเช่าบ้าน หรือ ค่าเช่าหอ\n");
    printf("2.ค่าผ่อนรถ\n");
    printf("3.ค่าน้ำ-ค่าไฟ\n");
    printf("4.ค่าโทรศัพท์\n");
    printf("5.อื่นๆ\n");
    scanf("%lf %lf %lf %lf %lf",&home, &car, &light, &phone, &value);
    cal = need-home-car-light-phone-value;
    if(cal < 0){
      printf("คุณใช้จ่ายมากเกินไป %.2lf บาท โปรดใช้จ่ายอย่างประหยัด\n",cal*-1);
    }
    else{
      printf("คุณมีค่าใช้จ่ายสิ่งที่จำเป็นเหลืออยู่ %.2lf บาท\n",cal);
    }
  }
  return 0;
}

int work_out(){
  double num,money,time_ot,typ,cal;
  printf("โปรดเลิอกกรอกข้อมูล\n");
  printf("1.ค่าตอบแทนกรณีทำงานล่วงเวลาปกติ/8ชม\n");
  printf("2.ค่าตอบแทนกรณีทำงาล่วงเวลาวันหยุด/8ชม\n");
  printf("3.ค่าตอบแทนกรณีทำงานในวันหยุดในช่วงเวลาปกติ/8ชม\n");
  scanf("%lf", &num);
  if(num == 1){
    printf("โปรดกรอกข้อมูลตามลำดับ\n");
    printf("1.ค่าจ้างต่อเดือน หรือ วัน\n");
    printf("2.เวลาการทำโอที/ชั่วโมง\n");
    printf("3.พนักงานรายเดือน =1, พนักงานรายวัน =0\n");
    scanf("%lf %lf %lf", &money, &time_ot, &typ);
    if(typ == 1){
      cal = (money/30/8)*1.5*time_ot;
      printf("คุณจะได้รับเงินโอทีรายเดือน = %.2lf บาท\n", cal);
    }
    else{
      cal = (money/8)*1.5*time_ot;
      printf("คุณจะได้รับเงินโอทีรายวัน = %.2lf บาท", cal);
    }
  }
  else if(num == 2){
    printf("โปรดกรอกข้อมูลตามลำดับ\n");
    printf("1.ค่าจ้างต่อเดือน หรือ วัน\n");
    printf("2.เวลาการทำโอที/ชั่วโมง\n");
    printf("3.พนักงานรายเดือน =1, พนักงานรายวัน =0\n");
    scanf("%lf %lf %lf", &money, &time_ot, &typ);
    if(typ == 1){
      cal = (money/30/8)*3*time_ot;
      printf("คุณจะได้รับเงินโอทีรายเดือน = %.2lf บาท\n", cal);
    }
    else{
      cal = (money/8)*3*time_ot;
      printf("คุณจะได้รับเงินโอทีรายวัน = %.2lf บาท", cal);
    }
  }
  else if(num == 3){
    printf("โปรดกรอกข้อมูลตามลำดับ\n");
    printf("1.ค่าจ้างต่อเดือน หรือ วัน\n");
    printf("2.เวลาการทำโอที/ชั่วโมง\n");
    printf("3.พนักงานรายเดือน =1, พนักงานรายวัน =0\n");
    scanf("%lf %lf %lf", &money, &time_ot, &typ);
    if(typ == 1){
      cal = (money/30/8)*1*time_ot;
      printf("คุณจะได้รับเงินโอทีรายเดือน = %.2lf บาท\n", cal);
    }
    else{
      cal = (money/8)*2*time_ot;
      printf("คุณจะได้รับเงินโอทีรายวัน = %.2lf บาท", cal);
    }
  }
  return 0;
}

int currencyy(){
  double num, amount, ans,che=1;
  char currency[10];
  printf("โปรกเลือกอัตราการแลกเปลี่ยน\n");
  printf("1.อัตราการซื้อ\n");
  printf("2.อัตราการขาย\n");
  scanf("%lf", &num);
  if(num == 1){
    printf("โปรดกรอกข้อมูลตามลำดับ\n");
    printf("1.สกุลเงินที่ต้องการแลกเปลี่ยนจากเงินไทย\n");
    printf("USD = ดอลลาร์\nEUR = ยูโร\nGBP = ปอนด์\nJPY = เยน\nCAD = ดอลลาร์แคนาดา\n");
    printf("CHF = ฟรังก์สวิส\nAUD = ดอลลาร์ออสเตรเลีย\nNZD = ดอลลาร์นิวซีแลนด์\nSGD = ดอลลาร์สิงคโปร์\nHKD = ดอลลาร์ฮองกง\n");
    printf("1.จำนวนเงินสกุลบาท\n");
    scanf("%s %lf", currency, &amount);
    if(strcmp(currency,"USD") == 0){
      ans = amount/(32.12);
      printf("%.2lf บาท = %.2lf USD", amount, ans);
    }
    else if(strcmp(currency,"EUR") == 0){
      ans = amount/(35);
      printf("%.2lf บาท = %.2lf EUR", amount, ans);
    }
    else if(strcmp(currency,"GBP") == 0){
      ans = amount/(40.10);
      printf("%.2lf บาท = %.2lf GBP", amount, ans);
    }
    else if(strcmp(currency,"JPY") == 0){
      ans = amount/(3.015);
      printf("%.2lf บาท = %.2lf JPY", amount, ans);
    }
    else if(strcmp(currency,"CAD") == 0){
      ans = amount/(23.10);
      printf("%.2lf บาท = %.2lf CAD", amount, ans);
    }
    else if(strcmp(currency,"CHF") == 0){
      ans = amount/(33.30);
      printf("%.2lf บาท = %.2lf CHF", amount, ans);
    }
    else if(strcmp(currency,"AUD") == 0){
      ans = amount/(20.70);
      printf("%.2lf บาท = %.2lf AUD", amount, ans);
    }
    else if(strcmp(currency,"NZD") == 0){
      ans = amount/(19.65);
      printf("%.2lf บาท = %.2lf NZD", amount, ans);
    }
    else if(strcmp(currency,"SGD") == 0){
      ans = amount/(22.90);
      printf("%.2lf บาท = %.2lf SGD", amount, ans);
    }
    else if(strcmp(currency,"HKD") == 0){
      ans = amount/(4.190);
      printf("%.2lf บาท = %.2lf HKD", amount, ans);
    }
    else{
      printf("ข้อมูลไม่ถูกต้อง\n");
      che = 0;
    }
    
    if(che == 1){
      printf("อ้างอิงข้อมูลวันที่26 เมษายน 2563 จากเว็บไซต์ superrichthailand");
    }
  }
  else if(num == 2){
    printf("โปรดกรอกข้อมูลตามลำดับ\n");
    printf("1.สกุลเงินที่ต้องการแลกเปลี่ยนเป็นเงินไทย\n");
    printf("USD = ดอลลาร์\nEUR = ยูโร\nGBP = ปอนด์\nJPY = เยน\nCAD = ดอลลาร์แคนาดา\n");
    printf("CHF = ฟรังก์สวิส\nAUD = ดอลลาร์ออสเตรเลีย\nNZD = ดอลลาร์นิวซีแลนด์\nSGD = ดอลลาร์สิงคโปร์\nHKD = ดอลลาร์ฮองกง\n");
    printf("1.จำนวนเงินที่ต้องการเปลี่ยนเป็นเงินไทย\n");
    scanf("%s %lf", currency, &amount);
    if(strcmp(currency,"USD") == 0){
      ans = amount*(31.75);
      printf("%.2lf USD = %.2lf บาท", amount, ans);
    }
    else if(strcmp(currency,"EUR") == 0){
      ans = amount*(34.80);
      printf("%.2lf EUR = %.2lf บาท", amount, ans);
    }
    else if(strcmp(currency,"GBP") == 0){
      ans = amount*(39.80);
      printf("%.2lf GBP = %.2lf บาท", amount, ans);
    }
    else if(strcmp(currency,"JPY") == 0){
      ans = amount*(3.005);
      printf("%.2lf JPY = %.2lf บาท", amount, ans);
    }
    else if(strcmp(currency,"CAD") == 0){
      ans = amount*(22.90);
      printf("%.2lf CAD = %.2lf บาท", amount, ans);
    }
    else if(strcmp(currency,"CHF") == 0){
      ans = amount*(33.15);
      printf("%.2lf CHF = %.2lf บาท", amount, ans);
    }
    else if(strcmp(currency,"AUD") == 0){
      ans = amount*(20.55);
      printf("%.2lf AUD = %.2lf บาท", amount, ans);
    }
    else if(strcmp(currency,"NZD") == 0){
      ans = amount*(19.40);
      printf("%.2lf NZD = %.2lf บาท", amount, ans);
    }
    else if(strcmp(currency,"SGD") == 0){
      ans = amount*(22.72);
      printf("%.2lf SGD = %.2lf บาท", amount, ans);
    }
    else if(strcmp(currency,"HKD") == 0){
      ans = amount*(4.170);
      printf("%.2lf HKD = %.2lf บาท", amount, ans);
    }
    else{
      printf("ข้อมูลไม่ถูกต้อง\n");
      che = 0;
    }
    if(che == 1){
      printf("อ้างอิงข้อมูลวันที่26 เมษายน 2563 จากเว็บไซต์ superrichthailand");
    }
  }
  return 0;
}

int installment(){
  double money, interest, time, inc,increase, ans;
  printf("กรุณากรอกข้อมูลตามลำดับ\n");
  printf("1.จำนวนเงินที่ต้องการผ่อน\n");
  printf("2.อัตราดอกเบี้ย เป็น%%\n");
  printf("3.ระยะเวลาในการผ่อน\n");
  scanf("%lf %lf %lf", &money, &interest, &time);
  inc = (money+(money*(interest/100)));
  for(increase=0 ; time > inc ; increase++){
    inc -= time;
  }
  printf("ท่านจะต้องผ่อนเดือนละ %.2lf บาท",increase);
  return 0;
}

int stair_tax(){
  double money,tax=0;
  printf("1.โปรดกรอกจำนวนเงินเดือนของท่าน\n");
  scanf("%lf", &money);
  if(money >=0 && money <= 150000){
    printf("คุณไม่ต้องเสียภาษี");
  }
  else if(money > 150000 && money <= 300000){
    tax += (money-150000)*0.05;
    printf("คุณต้องเสียภาษีเป็นเงินจำนวน %.2lf บาท", tax);
  }
  else if(money > 300000 && money <= 500000){
    tax += ((money-300000)*0.1)+7500;
    printf("คุณต้องเสียภาษีเป็นเงินจำนวน %.2lf บาท", tax);
  }
  else if(money > 500000 && money <= 750000){
    tax += ((money-500000)*0.15)+27500;
    printf("คุณต้องเสียภาษีเป็นเงินจำนวน %.2lf บาท", tax);
  }
  else if(money > 750000 && money <= 1000000){
    tax += ((money-750000)*0.20)+65000;
    printf("คุณต้องเสียภาษีเป็นเงินจำนวน %.2lf บาท", tax);
  }
  else if(money > 1000000 && money <= 2000000){
    tax += ((money-1000000)*0.25)+115000;
    printf("คุณต้องเสียภาษีเป็นเงินจำนวน %.2lf บาท", tax);
  }
  else if(money > 2000000 && money <= 5000000){
    tax += ((money-2000000)*0.30)+365000;
    printf("คุณต้องเสียภาษีเป็นเงินจำนวน %.2lf บาท", tax);
  }
  else if(money > 5000000){
    tax += ((money-5000000)*0.35)+1265000;
    printf("คุณต้องเสียภาษีเป็นเงินจำนวน %.2lf บาท", tax);
  }
  return 0;
}

int tax_car(){
  double engine, year, tax=0, total;
  printf("กรุณากรอกข้อมูลตามลำดับ\n");
  printf("1.ขนาดเครื่องยนต์\n");
  printf("2.อายุการใช้งาน\n");
  scanf("%lf %lf", &engine, &year);
  if(engine >= 1801){
    tax += (2100 + ((engine-1800)*4));
  }
  else if(engine >= 601 && engine <= 1800){
    tax += (300 + ((engine-600)*1.5));
  }
  else if(engine >= 1 && engine <= 600){
    tax += (engine*0.5);
  }

  if(year >= 10){
    total = tax*0.5;
  }
  else if(year >= 9 && year < 10){
    total = tax*0.6;
  }
  else if(year >= 8 && year < 9){
    total = tax*0.7;
  }
  else if(year >= 7 && year < 8){
    total = tax*0.8;
  }
  else if(year >= 6 && year < 7){
    total = tax*0.9;
  }
  else{
    total = tax;
  }
  printf("ต้องเสียภาษี %.2lf", total);
  return 0;
}

int interest(){
  double money, inter, year, in_now;
  int i;
  printf("กรุณากรอกข้อมูลตามลำดับ\n");
  printf("1.จำนวนเงินที่ฝาก หน่วยเป็นบาท\n");
  printf("2.อัตราดอกเบี้ยต่อปี เช่น ดอกเบี้ย 2%% ต่อปีให้กรอก 2\n");
  printf("3.จำนวนปีที่ฝาก\n");
  scanf("%lf %lf %lf", &money, &inter, &year);
  for(i=0 ; i < year ; i++){
    in_now = ((money*inter)/100);
    money = money+in_now;
  }
  printf("%.2lf บาท", money);
  return 0;
}
