//---------------------Variáveis---------------------------
int distancef;
int distancee;
int distanced;
long durationf;
long duratione;
long durationd;
unsigned long previousMillis = 0;   // Variável para armazenar o tempo da última leitura
unsigned long currentMillis = millis();  // Obtém o tempo atual
unsigned long interval = 100;  // Defina o intervalo desejado em milissegundos


//----------------------Sensores---------------------------
//frente
#define trigFrente 2
#define echoFrente 5
//esquerda
#define trigEsquerdo 4 
#define echoEsquerdo 6
//direita
#define trigDireita 7
#define echoDireita 3

//-----------------------Motores---------------------------
//esquerda
#define motorEsquerdo 9
#define motorEsquerdoTras 8
//direito
#define motorDireito 10
#define motorDireitoTras 12

void setup() {
    Serial.begin(9600); //inicia a porta serial
  //Sensores Ultrassônicos--------------
  pinMode(echoEsquerdo, INPUT); // define o pino X12 como entrada (recebe)
  pinMode(trigEsquerdo, OUTPUT); // define o pino X13 como saida (envia)
  pinMode(echoFrente, INPUT); // define o pino X10 como entrada (recebe)
  pinMode(trigFrente, OUTPUT); // define o pino X11 como saida (envia)
  pinMode(echoDireita, INPUT); // define o pino X8 como entrada (recebe)
  pinMode(trigDireita, OUTPUT); // define o pino X9 como saida (envia)
  //Motores----------------------------
  pinMode(motorEsquerdo, OUTPUT);
  pinMode(motorEsquerdoTras, OUTPUT);
  pinMode(motorDireito, OUTPUT);
  pinMode(motorDireitoTras, OUTPUT);
}

void loop() {
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Atualiza o tempo da última leitura

    measureDistance();  // Chama a função para medir a distância
  }

}

  void measureDistance() {
  digitalWrite(trigFrente, LOW);
  digitalWrite(trigDireita, LOW);
  digitalWrite(trigEsquerdo, LOW);
  delayMicroseconds(2);

  digitalWrite(trigFrente, HIGH);
  digitalWrite(trigDireita, HIGH);
  digitalWrite(trigEsquerdo, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigFrente, LOW);
  digitalWrite(trigDireita, LOW);
  digitalWrite(trigEsquerdo, LOW);

  durationf = pulseIn(echoFrente, HIGH);
  duratione = pulseIn(echoEsquedo, HIGH);
  durationd = pulseIn(echoDireita, HIGH);
  distancef = durationf * 0.034 / 2;  // Calcula a distância em centímetros
  distancee = duratione * 0.034 / 2;  // Calcula a distância em centímetros
  distanced = durationd * 0.034 / 2;  // Calcula a distância em centímetros

  Serial.print("Distância: ");
  Serial.print(distancef);
  Serial.println(" cm");

  Serial.print("Distância: ");
  Serial.print(distancee);
  Serial.println(" cm");

  Serial.print("Distância: ");
  Serial.print(distanced);
  Serial.println(" cm");
  }

   if ((distancef) >= 30 and (ditancee) <= 60 and (distanced) <= 60){
    frente(int velocidade);
   }
  }

void frente (255*0,2){
  analogWrite(motorEsquerdo, velocidade);
  analogWrite(motorDireito, velocidade);
  Estabilizar();
}