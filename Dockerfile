# Используем базовый образ Ubuntu
FROM ubuntu:latest

# Устанавливаем необходимые пакеты
RUN apt-get update && \
    apt-get install -y cmake libpq-dev g++ && \
    apt-get clean

# Устанавливаем рабочую директорию
WORKDIR /app

# Копируем все файлы из папки app в контейнер
COPY ./app .

# Создаем директорию для сборки
RUN mkdir build && cmake -B build -S . && cmake --build build

# Запускаем исполняемый файл Commander
# CMD ["./build/Commander/Commander"]
