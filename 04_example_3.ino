#define PIN_LED 13
unsigned int count,precount,toggle;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
  while (!Serial) {
    ;
  }
  Serial.println("Hello World");
  count = toggle ;
  digitalWrite(PIN_LED, toggle);
}

void loop() {
  Serial.println(++count);
  toggle = toggle_state(toggle);
  digitalWrite(PIN_LED, toggle);
  delay(1000);
}

int toggle_state(int toggle) {
  unsigned long count = millis();
  if (count - precount >= 1000) {
    precount = count;
    toggle = 1;
  }
  else
    toggle = 0;
  return toggle;
}
