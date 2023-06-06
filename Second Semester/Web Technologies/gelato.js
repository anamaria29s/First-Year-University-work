
function enlargeImage(image) {
    if (image.classList.contains("enlarged")) {
        image.style.transform = "scale(1)";
        image.classList.remove("enlarged");
    } else {
        image.style.transform = "scale(1.2)";
        image.classList.add("enlarged");
    }
}


function sortMenus(columnIndex) {
    var menuColumn = document.getElementsByClassName('menu-column')[columnIndex];
    var menuItems = menuColumn.getElementsByClassName('single-menu');

    var sortedMenus = Array.from(menuItems).sort(function(a, b) {
        var titleA = a.getElementsByClassName('menu-content')[0].getElementsByTagName('h5')[0].innerText.toLowerCase();
        var titleB = b.getElementsByClassName('menu-content')[0].getElementsByTagName('h5')[0].innerText.toLowerCase();

        if (titleA < titleB) {
            return -1;
        }
        if (titleA > titleB) {
            return 1;
        }
        return 0;
    });

    for (var i = 0; i < sortedMenus.length; i++) {
        menuColumn.appendChild(sortedMenus[i]);
    }
}