x = [-1, -8, -14, -19, -22, -26, -33, -38];
y = [23, 24, 27, 30, 30, 33, 33, 37];
n = 10;
plot(x,y);
grid on

a1 = (sum(x) * sum(y) - n * x * y') / (sum(x) ^ 2 - n * sum(x .^ 2));
a0 = 1 / n * (sum(y) - a1 * sum(x));

y1 = a0 + a1 * x;
hold on
plot(x, y1);
hold off
legend('Исходная функция', 'Аппроксимирующая функция');