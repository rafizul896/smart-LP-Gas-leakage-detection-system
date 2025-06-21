#include <Servo.h>  // সার্ভো মোটর নিয়ন্ত্রণের জন্য লাইব্রেরি যুক্ত করা হয়েছে

// সেন্সর ও এক্সেসরিজ পিন ডেফিনেশন
const int mq2Pin = A0;        // MQ-2 গ্যাস সেন্সরের এনালগ আউটপুট পিন (A0)
const int fanPin = 8;         // ফ্যান সংযুক্ত করা হয়েছে D8 পিনে
const int buzzerPin = 7;      // প্যাসিভ বাজার সংযুক্ত করা হয়েছে D7 পিনে
const int servoPin = 9;       // সার্ভো মোটর সংযুক্ত করা হয়েছে D9 পিনে

const int threshold = 250;    // গ্যাস লিকেজ সনাক্তের জন্য থ্রেশহোল্ড মান
const int safeAngle = 0;      // স্বাভাবিক অবস্থায় সার্ভো মোটরের এঙ্গেল (ভাল্ভ খোলা)
const int offAngle = 120;     // গ্যাস লিকেজ হলে সার্ভো ঘুরে ভাল্ভ বন্ধ করবে (120°)

// সার্ভো অবজেক্ট তৈরি
Servo regulatorServo;

void setup() {
  Serial.begin(9600);               // সিরিয়াল মনিটর শুরু (ডিবাগিং/রিডিং দেখার জন্য)
  pinMode(fanPin, OUTPUT);          // ফ্যান আউটপুট হিসেবে সেট করা
  pinMode(buzzerPin, OUTPUT);       // বাজার আউটপুট হিসেবে সেট করা
  regulatorServo.attach(servoPin);  // সার্ভো মোটর নির্দিষ্ট পিনে সংযুক্ত করা
  regulatorServo.write(safeAngle);  // প্রারম্ভিক অবস্থায় ভাল্ভ খোলা রাখুন
}

void loop() {
  int gasValue = analogRead(mq2Pin);   // MQ-2 সেন্সর থেকে গ্যাসের মান পড়া
  Serial.print("Gas sensor reading: ");
  Serial.println(gasValue);            // মান সিরিয়াল মনিটরে দেখানো

  if (gasValue > threshold) {          // যদি গ্যাসের মান থ্রেশহোল্ড এর চেয়ে বেশি হয়
    Serial.println("⚠ Gas leakage detected!"); // মনিটরে সতর্কবার্তা দেখানো
    digitalWrite(fanPin, HIGH);        // ফ্যান চালু করা
    tone(buzzerPin, 2000);             // বাজার বাজানো (২০০০ হার্জ ফ্রিকোয়েন্সিতে)
    regulatorServo.write(offAngle);    // সার্ভো ঘুরে ভাল্ভ বন্ধ করা (১২০ ডিগ্রিতে)
    delay(2000);                       // ২ সেকেন্ড অপেক্ষা করা (সার্ভো চলার সময়)
  } else {
    digitalWrite(fanPin, LOW);         // গ্যাস না থাকলে ফ্যান বন্ধ করা
    noTone(buzzerPin);                 // বাজার বন্ধ করা
    regulatorServo.write(safeAngle);   // সার্ভো আবার স্বাভাবিক অবস্থায় ফেরানো (ভাল্ভ খোলা)
  }

  delay(500);  // প্রতি ০.৫ সেকেন্ড পর পর সেন্সরের মান আবার পড়া হবে
}
