# Uzay Simülasyonu - C Projesi

**Hazırlayan:** Abdul Matin HAQEQAT  
**Öğrenci No:** 24360859224  
**Bölüm:** Bilgisayar Mühendisliği  
**Ders:** Algoritmalar ve Programlama  
**Dönem:** 2025-2026 Güz Dönemi  

---

## Proje Tanımı

Bu proje bireysel olarak geliştirilmiştir. Konsol tabanlı bir uzay simülasyonu uygulamasıdır. Program; bilim insanının 9 farklı fizik deneyini seçip, Güneş Sistemi gezegenlerinde simülasyon yapmasına ve sonuçları ekranda görüntülemesine olanak sağlar.  

Tüm kullanıcı etkileşimi, programın çalıştığı konsol ekranı üzerinden gerçekleştirilir ve metin tabanlı çıktılar üretilir. Grafik veya görsel arayüz içermez.

---

## Deneyler

Programda aşağıdaki deneyler bulunmaktadır:

1. **Serbest Düşme Deneyi**  
2. **Yukarı Atış Deneyi**  
3. **Ağırlık Deneyi**  
4. **Kütleçekimsel Potansiyel Enerji Deneyi**  
5. **Hidrostatik Basınç Deneyi**  
6. **Arşimet Kaldırma Kuvveti Deneyi**  
7. **Basit Sarkaç Periyodu Deneyi**  
8. **Sabit İp Gerilmesi Deneyi**  
9. **Asansör Deneyi**

Her deney için gerekli girdiler kullanıcıdan alınır ve Güneş Sistemi gezegenleri üzerinde hesaplanan sonuçlar alt alta ekranda gösterilir. Hatalı girişler veya negatif değerler durumunda program uyarı verir ve tekrar girdi ister.

---

## Teknik Detaylar

### 1. Program Akışı ve Modüler Yapı
- Bilim insanı adı alınır.
- Deney menüsü ekrana basılır.
- Kullanıcı deney seçer.
- Gerekli metrikler girilir.
- Tüm gezegenlerde simülasyon yapılır ve sonuçlar yazdırılır.
- Tüm deneyler ayrı fonksiyonlarda hesaplanır.
- Diziler ve gezegen yerçekimi ivmeleri **pointer mantığıyla** kullanılır.

### 2. Gezegen Verileri ve Sabitler
- Gezegenlerin yerçekimi ivmeleri bir dizi içinde tutulur:
  - Merkür → index 0
  - Venüs → index 1
  - …  
  - Neptün → index 7
- Tüm ölçü birimleri SI birimleriyle (kg, m, s, J) verilmiştir.

### 3. Deneylerin Hesaplama Mantığı
- Her deney için alınan girdiler ve formüller kullanılır:
  - Serbest düşme: \(h = \frac{1}{2} g t^2\)  
  - Yukarı atış: \(h_{max} = \frac{v_0^2}{2g}\)  
  - Ağırlık: \(G = m g\)  
  - Kütleçekimsel enerji: \(E_p = m g h\)  
  - Hidrostatik basınç: \(P = \rho g h\)  
  - Arşimet kuvveti: \(F_k = \rho g V\)  
  - Basit sarkaç: \(T = 2 \pi \sqrt{\frac{L}{g}}\)  
  - Sabit ip: \(T = m g\)  
  - Asansör: \(N = m (g \pm a)\)  

### 4. Girdi Doğrulama ve Hata Yönetimi
- Tüm negatif değerler **ternary operator** ile mutlak değere çevrilir.  
- Menüler dışında seçim yapılırsa uyarı verilir ve tekrar giriş istenir.

---

## Kurulum ve Çalıştırma

1. Kodları derleyin (örnek GCC):
   ```bash
   gcc main.c -o simulation
