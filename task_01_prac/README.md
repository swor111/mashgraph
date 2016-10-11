
## Запуск
1) Распакуйте архив
2) cd task_01_prac
3) make all


## Требования
Ubuntu x64
QMake version 2.01a
Using Qt version 4.8.7

libs path - run without qt: 
https://drive.google.com/open?id=0B_BgJJ4B78JRTUhWTEpfMU5POWc


## Устройство проекта
В папке src находится 2 Qt проекта: align_console и align_gui, а
также папка plugins и Makefile, который собирает оба проекта в папку bin
и все плагины в папке plugins в папку bin/plugins. Папка src/shared
содержит файлы, которые используются не только в 1 проекте (исходники 
модели, абстрактные классы плагина и т.п.)


## GUI
Интерфейс представляет собой кнопочки для взаимодействия с программой и 
стек изображений, который растет влево (новое изображение появляется    
слева, тогда как предыдущие съезжают вправо). Таким образом, сначала    
нужно выбрать изображение, затем совместить его каналы, а затем         
последовательно применять фильтры - фильтр применяется к последнему     
изображению (самому левому). 

Для того, чтобы вернуться к предыдущему изображению, есть кнопочка Back. 

Для того, чтобы сохранить последнее изображение - Save. ИЗОБРАЖЕНИЕ
СОХРАНЯЕТСЯ В ТУ ЖЕ ПАПКУ, ГДЕ ЛЕЖИТ ОРИГИНАЛ, в подпапке output с тем 
же именем. Например, если путь к загруженному изображению /home/p.bmp,
то Save сохранит последнее изображение в /home/output/p.bmp.

Если запуск происходит из папки bin, то фильтры при запуске пытаются
загрузиться из bin/plugins (то есть по относительному пути ./plugins)


## Console interface
Интерфейс консоли полностью повторяет GUI, наберите команду help для 
справки. Плагины по умолчанию не загружаются, их нужно загрузить ручками
командой load.


## Реализация MVC
Модель определена явно класс Model и вынесена в shared.
Контроллером в консольной версии является Controller, в gui MainWindow 
выступает его роли.
Вью в консольной версии - Printer, в gui - PluginContainer, который 
содержит стек ImageHolder-ов.

Взаимодействие model-view реализовано с помощью паттерна Наблюдатель, 
встроенного в Qt - signals & slots.