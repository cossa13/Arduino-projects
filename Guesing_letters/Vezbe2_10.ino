char slovo;
char rec[64];
char rec_1[64];
int duzina;
char cistac;
int pogodak = 0;
int game_over = 0;
int brojac = 0;
boolean flag_brojac = false;


void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Unesite rec: ");
  while(!Serial.available());
  delay(100);
  duzina = Serial.available();
  Serial.readBytes(rec, duzina);
  rec[duzina] = 0;
  delay(100);
  for(int i = 0;i < duzina;i++)
  {
    rec_1[i] = '_';
  }
  rec_1[duzina - 1] = '\0';
  Serial.println(rec_1);
  do
  {
    Serial.println("Unesite slovo: ");
    while(!Serial.available());
    delay(100);
    slovo = Serial.read();
    delay(100);
    for(int i = 0;i < duzina;i++)
    {
      if(rec[i] == slovo)
      {
        rec_1[i] = slovo;
      }
    }
    Serial.println(rec_1);
    flag_brojac = true;
    for(int j = 0;j < duzina;j++)
    {
      if(slovo == rec[j])
      {
        flag_brojac = false;
      }
    }
    if(flag_brojac == true)
    {
      brojac++;
    }
    cistac = Serial.read();
    delay(100);
    if(brojac == 5)
    {
      Serial.println("GAME OVER");
    }
  }while(brojac <= 4);
  brojac = 0;
}
