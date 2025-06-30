# ESP32 RGB LED Control Project

Bu proje ESP32 mikrodenetleyicisi kullanarak RGB LED kontrolü yapan bir ESP-IDF uygulamasıdır. WiFi bağlantı durumlarını farklı renklerle gösterir.

## Özellikler

- **RGB LED Kontrolü**: PWM kullanarak RGB LED'in rengini kontrol eder
- **WiFi Durum Göstergesi**: Farklı WiFi durumları için farklı renkler
- **FreeRTOS Tabanlı**: Çoklu görev desteği ile çalışır

## Donanım Gereksinimleri

- ESP32 Development Board
- RGB LED (Common Cathode)
- 3x 220Ω Direnç
- Breadboard ve jumper kablolar

## Pin Bağlantıları

| RGB LED | ESP32 GPIO |
|---------|------------|
| Red     | GPIO 21    |
| Green   | GPIO 22    |
| Blue    | GPIO 23    |
| GND     | GND        |

## Renk Kodları

| Durum | Renk | RGB Değeri |
|-------|------|------------|
| WiFi App Started | Magenta | (255, 102, 255) |
| HTTP Server Started | Lime | (204, 255, 51) |
| WiFi Connected | Cyan | (0, 255, 153) |

## Proje Yapısı

```
├── CMakeLists.txt
├── main/
│   ├── CMakeLists.txt
│   ├── main.c              # Ana uygulama dosyası
│   ├── rgb_led.c           # RGB LED kontrol fonksiyonları
│   └── rgb_led.h           # RGB LED header dosyası
├── .vscode/                # VS Code ayarları
└── README.md
```

## Kurulum ve Çalıştırma

### Gereksinimler
- ESP-IDF v4.4 veya üzeri
- VS Code + ESP-IDF Extension (opsiyonel)

### Adımlar

1. **Projeyi klonlayın:**
   ```bash
   git clone <repository-url>
   cd udemy_esp
   ```

2. **ESP-IDF ortamını kurun:**
   ```bash
   get_idf  # veya ESP-IDF kurulum yolunuzu source edin
   ```

3. **Projeyi derleyin:**
   ```bash
   idf.py build
   ```

4. **ESP32'ye yükleyin:**
   ```bash
   idf.py flash
   ```

5. **Seri monitörü başlatın:**
   ```bash
   idf.py monitor
   ```

## Kod Açıklaması

### main.c
- Ana uygulama döngüsü
- RGB LED durumları arasında geçiş yapar
- Her durum 1 saniye sürer

### rgb_led.c/h
- LEDC (LED Controller) kullanarak PWM sinyalleri üretir
- RGB LED'in her renk kanalını ayrı ayrı kontrol eder
- Farklı WiFi durumları için önceden tanımlanmış renkler

## Geliştirme Notları

- PWM frekansı: 100 Hz
- Çözünürlük: 8-bit (0-255 değer aralığı)
- Timer: LEDC_TIMER_0
- Mod: High Speed Mode

## Sorun Giderme

1. **Derleme hatası**: `idf.py clean` ardından `idf.py build` deneyin
2. **LED yanmıyor**: Pin bağlantılarını ve direnç değerlerini kontrol edin
3. **Renkler doğru değil**: Common anode/cathode LED tipini kontrol edin

## Lisans

Bu proje MIT lisansı altında yayınlanmıştır.
