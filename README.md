# Jogo de Dados com Arduino e LCD

Este projeto é um jogo de dados simples usando um Arduino e um display LCD. Quando o botão é pressionado, dois dados são "lançados" aleatoriamente, e o resultado é exibido no LCD.

## Componentes Necessários
- Arduino (qualquer modelo compatível com a biblioteca `Wire.h`)
- Display LCD com interface I2C (16x2)
- Botão de pressão
- Resistor de 10k (para o botão)

## Configuração do Circuito
- Conecte o display LCD ao Arduino via I2C.
- Conecte o botão ao pino 3 do Arduino e use um resistor de 10k para puxar o pino para o nível alto (pull-up).

## Bibliotecas Utilizadas
- `Wire.h`: Para comunicação I2C com o display LCD.
- `LiquidCrystal_I2C.h`: Para controlar o display LCD I2C.

## Funcionamento do Jogo
1. Ao iniciar, o LCD exibe "Bem Vindo!".
2. O usuário pressiona o botão para "lançar" os dados.
3. Os valores dos dois dados e a soma são exibidos no LCD.
4. Se a soma for 7 ou 11, o usuário ganha imediatamente.
5. Se a soma for 2, 3 ou 12, o usuário perde imediatamente.
6. Qualquer outro valor se torna o 'ponto', e o usuário deve continuar lançando os dados até igualar o 'ponto' para ganhar ou tirar 7 para perder.

## Código
O código está estruturado da seguinte forma:
- Inicialização do display LCD e configuração do botão.
- Loop principal que aguarda o pressionamento do botão, realiza o lançamento dos dados e verifica as condições de vitória ou derrota.

## Personalização
Você pode personalizar o jogo alterando as condições de vitória/derrota ou adicionando novas funcionalidades, como um sistema de pontuação ou níveis de dificuldade.

## Contato:

Se você tiver alguma dúvida ou sugestão, sinta-se à vontade para abrir uma issue no repositório do GitHub ou enviar um e-mail para: 
[nathanfelipi2006@gmail.com].

---

Desenvolvido com ❤️ por [Nathan Felipi Almeida].
