#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display LCD no endereço 0x27 e define suas dimensões (16 colunas por 2 linhas)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int botaoPin = 3; // Define o pino onde o botão está conectado

void setup() {
  // Inicia o display LCD
  lcd.init();
  lcd.backlight();

  // Configura o pino do botão como entrada
  pinMode(botaoPin, INPUT_PULLUP);

  // Configura a semente do gerador de números aleatórios
  randomSeed(analogRead(0));
}

void loop() {
  lcd.clear();
  lcd.print("Bem Vindo!");
  
  // Aguarda o clique do botão para iniciar o lançamento
  while(digitalRead(botaoPin) == HIGH) {
    // Fica em espera até que o botão seja pressionado
  }
  
  // Simula o lançamento de dois dados
  int dado1 = random(1, 7);
  int dado2 = random(1, 7);
  int soma = dado1 + dado2;

  // Exibe os valores dos dados e a soma no LCD
  lcd.clear();
  lcd.print("Dado1: ");
  lcd.print(dado1);

  lcd.setCursor(0, 1); // Move o cursor para a segunda linha
  lcd.print("Dado2: ");
  lcd.print(dado2);
  delay(2000); // Aguarda 2 segundo antes de prosseguir

  lcd.clear();
  lcd.print("Soma: ");
  lcd.print(soma);
  delay(2000);

  // Verifica as condições de vitória ou derrota
  if (soma == 7 || soma == 11) {
    // Vitória no primeiro lançamento
    lcd.clear();
    lcd.print("Vitoria!");
    delay(2000);
    // Reinicia o jogo

  } else if (soma == 2 || soma == 3 || soma == 12) {
    // Derrota no primeiro lançamento
    lcd.clear();
    lcd.print("Derrota!");
    delay(2000);
    // Reinicia o jogo

  } else {
    // O número lançado se torna o 'ponto'
    int ponto = soma;
    lcd.clear();
    lcd.print("Ponto: ");
    lcd.print(ponto);
    delay(2000);

    // Continua lançando os dados até igualar o 'ponto' ou tirar 7
    bool fimDoJogo = false;
    while (!fimDoJogo) {
      lcd.clear();
      lcd.print("Pressione...");
      
      // Aguarda o clique do botão para lançar novamente
      while(digitalRead(botaoPin) == HIGH) {
        // Fica em espera até que o botão seja pressionado
      }
      
      dado1 = random(1, 7);
      dado2 = random(1, 7);
      soma = dado1 + dado2;

      lcd.clear();
      lcd.print("Dado1: ");
      lcd.print(dado1);
      lcd.setCursor(0, 1);
      lcd.print("Dado2: ");
      lcd.print(dado2);
      delay(2000);
      lcd.clear();
      
      lcd.print("Soma: ");
      lcd.print(soma);
      delay(2000);
      
      if (soma == ponto) {
        // Vitória ao igualar o 'ponto'
        lcd.clear();
        lcd.print("Vitoria!");
        fimDoJogo = true;
      } else if (soma == 7) {
        // Derrota ao tirar 7
        lcd.clear();
        lcd.print("Derrota!");
        fimDoJogo = true;
      }
    }
  }
  // Aguarda 3 segundos antes de reiniciar o jogo
  delay(3000);
}
