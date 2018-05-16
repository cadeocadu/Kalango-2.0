// Esta biblioteca fornece uma função e uma tarefa para fazer cada tipo de giro
// necessário, que pode ser de 90 ou 180 todas sao herdadas na inclusão da
// biblioteca.
// as tarefas são ideais para serem executadas ao mesmo tempo que outras
// funções sao ideais para serem usadas em sequência
// gira_90_Hor() -- função gira 90 graus no sentido horario
// gira_90_Ant() -- função gira 90 graus no sentido anti-horário
// tGira_90_Hor -- tarefa gira 90 graus no sentido horário
// tGira_90_Ant -- tarefa gira 90 graus no sentido anti-horário

int power = 100;
long grau = 475, grau_neg = -475;

//funçoes para girar no sentido horario
//RotateMotorPID(byte outputs, char pwr, long angle, byte p, byte i, byte d)
void ligar_a_Hor() {
  RotateMotorPID(OUT_A, power, grau, 50, 50, 50);
  TextOut(0, 40,"motor A hor\n");
}

void ligar_b_Hor() {
  RotateMotorPID(OUT_C, power, grau_neg, 50, 50, 50);
  TextOut(0, 40,"motor B hor\n");
}
// funçoes para girar no sentido anti-horario
void ligar_a_Ant() {
  RotateMotorPID(OUT_A, power, 475, 50, 50, 50);
  TextOut(0, 40,"motor A ant\n");
}

void ligar_b_Ant() {
  RotateMotorPID(OUT_C, power, -475, 50, 50, 50);
  TextOut(0, 40,"motor B ant\n");
}
//---------------------------------------------
void gira_90_Hor(){
    ligar_a_Hor();
    ligar_b_Hor();
    TextOut(0, 40,"gira 90 hor\n");
}

task tGira_90_Hor(){
  gira_90_Hor();
}
task tGira_180_Hor(){
  gira_90_Hor();
  gira_90_Hor();
}
//--anti-horarios
void gira_90_Ant(){
    ligar_a_Ant();
    ligar_b_Ant();
    TextOut(0, 40,"gira 90 ant\n");
}

task tGira_90_Ant(){
  gira_90_Ant();
}
task tGira_180_Ant(){
  gira_90_Ant();
  gira_90_Ant();
}
//void ande(int tempo, )
