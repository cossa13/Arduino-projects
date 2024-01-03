int broj = 0;
char pretpostavka;
int pogodak = 0;
boolean game_over = false;
int random_broj = 0;
int random_broj_1 = 0;
char cistac;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  random_broj = random(1, 101);
  Serial.println(random_broj);
  Serial.println("Unesite vasu pretpostavku: ");
  while(!Serial.available());
  delay(100);
  pretpostavka = Serial.read();
  delay(100);
  if(pretpostavka == 'v')
  {
    random_broj_1 = random(1, 101);
    if(random_broj_1 > random_broj)
    {
      pogodak++;
    }
    else
    {
      game_over = true;
    }
  }
  else if(pretpostavka == 'm')
  {
    random_broj_1 = random(1, 101);
    if(random_broj_1 < random_broj)
    {
      pogodak++;
    }
    else
    {
      game_over = true;
    }
  }
  else
  {
    Serial.println("Neispravan unos!");
  }
  if(game_over == true)
  {
    Serial.println("Vise srece drugi put!");
    game_over = false;
    pogodak = 0;
  }
  if(pogodak == 3)
  {
    Serial.println("POBEDA");
    game_over = false;
    pogodak = 0;
  }
  cistac = Serial.read();
  delay(100);
}
