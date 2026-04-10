# 🤝 Contributing to Computer Store Management System

Thank you for considering contributing! Here's how to get started.

---

## 📌 Ways to Contribute

- 🐛 **Bug fixes** — fix crashes, logic errors, or input handling issues
- ✨ **New features** — add new functionality to the store system
- 🎨 **UI improvements** — improve terminal layout or color formatting
- 📝 **Documentation** — improve README or add code comments
- 🔐 **Encryption** — replace/improve the Caesar cipher with a stronger algorithm

---

## 🚀 Getting Started

1. **Fork** the repository on GitHub
2. **Clone** your fork locally:
   ```bash
   git clone https://github.com/YOUR_USERNAME/computer-store-management.git
   cd computer-store-management
   ```
3. **Create a branch** for your change:
   ```bash
   git checkout -b feature/your-feature-name
   ```
4. **Build and test** your changes:
   ```bash
   # macOS
   g++ -o main main.cpp Laptop.cpp utils.cpp encryption.cpp -framework AudioToolbox && ./main

   # Linux
   g++ -o main main.cpp Laptop.cpp utils.cpp encryption.cpp && ./main

   # Windows
   g++ -o main.exe main.cpp Laptop.cpp utils.cpp encryption.cpp && main.exe
   ```
5. **Commit** your changes with a clear message:
   ```bash
   git commit -m "Fix: correct budget validation in take_order()"
   ```
6. **Push** to your fork:
   ```bash
   git push origin feature/your-feature-name
   ```
7. Open a **Pull Request** on GitHub and describe what you changed and why.

---

## 📐 Code Style Guidelines

- Use clear, descriptive variable and function names
- Keep functions focused — one responsibility per function
- Add comments for any logic that isn't immediately obvious
- Follow the existing formatting style (indentation, braces, spacing)
- Test on at least one platform (Windows, Linux, or macOS) before submitting

---

## 🐛 Reporting Bugs

Open a GitHub Issue and include:
- Your OS and compiler version (`g++ --version`)
- Steps to reproduce the bug
- What you expected vs. what actually happened

---

## 💡 Suggesting Features

Open a GitHub Issue with the label `enhancement` and describe:
- What the feature does
- Why it would be useful
- Any ideas on how to implement it

---

## 📄 License

By contributing, you agree that your contributions will be licensed under the same open-source license as this project.