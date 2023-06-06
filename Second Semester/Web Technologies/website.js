window.addEventListener('DOMContentLoaded', (event) => {
    const iceCreamImages = [
      'gelato1.jpg',
      'gelato2.jpg',
      'gelato3.jpg',
      'gelato4.jpg',
      'gelato5.jpg'
    ];

    const container = document.querySelector('.image');
    const randomImage = iceCreamImages[Math.floor(Math.random() * iceCreamImages.length)];
    const iceCreamImage = document.createElement('img');
    iceCreamImage.src = randomImage;
    container.appendChild(iceCreamImage);
  });