# 🐍 Snake Game

[🇹🇷 Türkçe](#-yılan-oyunu)

This is a simple **Snake Game** built using **C++ and SDL**.

### 🎮 Gameplay
- Control the snake using **arrow keys (↑ ↓ ← →)** or **WASD**.
- Eat the apple to grow and increase your score.
- Don't hit yourself!

### 📌 Requirements
Before running the game, make sure you have the following installed:
- C++ compiler (g++ or clang++)
- SDL2 library
- CMake

### 🔧 Installation & Running the Game
1. **Clone the repository:**
   ```sh
   git clone https://github.com/Berkopan/SnakeGame
   cd SnakeGame
   ```
2. **Build the project:**
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```
3. **Run the game:**
   ```sh
   ./snake_game
   ```
   
**Note:** In the CMakeLists.txt file, the SDL2 library is linked using a direct path, which may vary between different users. Please update the path accordingly to match your system's SDL2 installation.

   ---
# 🐍 Yılan Oyunu

[🇬🇧 English](#-snake-game)

Bu proje C++ ve SDL kullanılarak geliştirilen basit bir Yılan Oyunudur.

### 🎮 Oynanış
- Yılanı yön tuşları (↑ ↓ ← →) veya WASD ile kontrol edin.
- Elmayı yiyerek büyüyün ve skorunuzu artırın.
- Kendinize çarpmayın.

### 📌 Gereksinimler
Oyunu çalıştırmadan önce aşağıdaki bileşenlerin yüklü olduğundan emin olun:
- C++ derleyicisi (g++ ve clang++)
- SDL2 kütüphanesi
- CMake

### Kurulum ve Çalıştırma
1. **Projeyi klonlayın:**
   ```sh
   git clone https://github.com/Berkopan/SnakeGame
   cd SnakeGame
   ```
2. **Projeyi derleyin:**
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```
3. **Oyunu çalıştırın:**
   ```sh
   ./snake_game
   ```
**Not:** CMakeLists.txt dosyasında SDL2 kütüphanesi doğrudan bir yol (path) belirterek projeye dahil edilmiştir. Ancak, bu yol kullanıcıya bağlı olarak değişiklik gösterebilir. Lütfen kendi sisteminizdeki SDL2 kurulumuna uygun olacak şeklde yolu güncelleyiniz. 