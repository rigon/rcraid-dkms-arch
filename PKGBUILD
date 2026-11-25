_pkgbase=rcraid
pkgname=rcraid-dkms
pkgver=17.2.1
pkgrel=2
pkgdesc="AMD AM4 socket X370 chipset motherboard NVMe/SATA RAID driver (DKMS)"
arch=('i686' 'x86_64')
url="https://www.amd.com/en/support/chipsets/amd-socket-am4/x370"
license=('GPL2')
depends=('dkms')
optdepends=('linux-headers: build the module for linux'
            'linux-lts-headers: build the module for linux-lts')
# conflicts=("${_pkgbase}")
# install=${pkgname}.install
source=('manual://raid_linux_driver_8_01_00_039_public.zip'
        'dkms.conf'
        'linux-4.15.patch'
        'linux-5.4.patch'
        'linux-5.6.patch'
        'linux-5.14.patch'
        'linux-5.15.patch'
        'linux-5.17.patch'
        'linux-5.18.patch'
        'linux-6.2.patch'
        'linux-6.4.patch'
        'linux-6.6.patch'
        'linux-6.9.patch'
        'linux-6.11.patch'
        'linux-6.14.patch'
        'linux-6.15.patch'
        'linux-6.16.patch'
        'linux-6.18.patch'
        'conftest.patch'
        'conftest.sh'
        'conftest.Kbuild'
        'bios_param_gendisk.c'
        'timer_delete_sync.c')
md5sums=('f5692d2ef952f8c903af90cdd9eb3ce6'
         '6f78c424353ae927e81bcbfec67afece'
         '461866e715a1fded49a3f7c043a173d7'
         'cac98de11cc5bd61fff72ff1c8cf363d'
         'bd1ef2b6bcefaec0abf7a832e937f01a'
         '956ccadfdf4fc4188ec0ab79b7311a71'
         '86d51a674e9d8a1aa56a1bb9d741ec8f'
         '978b50c203e156a09977052efc4fe2a5'
         '17ebd1ffddd4cc708117db8ec010c12e'
         'cd542069132376cc10cf0694f309763f'
         'b7e7e4567895a3fd377646113cc7af40'
         '0e2cbf17fefd34917f849073c25f63b6'
         'c171e789b72bd9d6cf68f7fa63dec366'
         '8843beaa9a544bfb5ac6c288a322cb9f'
         'ea3b996a096c3d3360daba6f89844726'
         '08ee10bca2011934eb58880e5dc17b70'
         'e4bd4da3dd8c87d8b03d0b52f9a7ebf4'
         'dbfa02271bc32c52cb4a9100cd691eeb'
         '57b6fed40f57d3b9cf9a68ca9fb7bb80'
         '63f5947ab8e5a7b165a0b5348f8fb086'
         'cdb4406ad6af94f00bc18f0198ba2920'
         '57fee6796fe58c9aafb7edc665950d90'
         'a8f49b881b54f920ef2a5b91f064a7f6')

prepare() {
    rm -rf ${_pkgbase}-${pkgver}
    mkdir ${_pkgbase}-${pkgver}
    cp driver_sdk/src/* ${_pkgbase}-${pkgver}
    cd ${_pkgbase}-${pkgver}

    # Patching the source code
    patch -Np1 -i ../linux-4.15.patch
    patch -Np1 -i ../linux-5.4.patch
    patch -Np1 -i ../linux-5.6.patch
    patch -Np1 -i ../linux-5.14.patch
    patch -Np1 -i ../linux-5.15.patch
    patch -Np1 -i ../linux-5.17.patch
    patch -Np1 -i ../linux-5.18.patch
    patch -Np1 -i ../linux-6.2.patch
    patch -Np1 -i ../linux-6.4.patch
    patch -Np1 -i ../linux-6.6.patch
    patch -Np1 -i ../linux-6.9.patch
    patch -Np1 -i ../linux-6.11.patch
    patch -Np1 -i ../linux-6.14.patch
    patch -Np1 -i ../linux-6.15.patch
    patch -Np1 -i ../linux-6.16.patch
    patch -Np1 -i ../linux-6.18.patch

    # Kernel feature detection
    patch -Np1 -i ../conftest.patch
    install -Dm644 ../conftest.sh conftest.sh
    install -Dm644 ../conftest.Kbuild conftest/Kbuild
    install -Dm644 ../bios_param_gendisk.c conftest/bios_param_gendisk.c
    install -Dm644 ../timer_delete_sync.c conftest/timer_delete_sync.c
}

package() {
    local dest="${pkgdir}"/usr/src/${_pkgbase}-${pkgver}

    install -Dm644 dkms.conf "${dest}"/dkms.conf
    sed -e "s/@_PKGBASE@/${_pkgbase}/" \
        -e "s/@PKGVER@/${pkgver}/" \
        -i "${dest}"/dkms.conf

    cp -r ${_pkgbase}-${pkgver}/* "${dest}"/
}
