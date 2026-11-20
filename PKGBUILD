# Maintainer: foo <foo(at)example(dot)org>
# Contributor: bar <bar(at)example(dot)org>
_kver=$(uname -r)
_pkgbase=rcraid
pkgname=rcraid-dkms
pkgver=17.2.1
pkgrel=2
pkgdesc="AMD AM4 socket X370 chipset motherbroad NVMe/SATA RAID driver (DKMS)"
arch=('i686' 'x86_64')
url="https://www.amd.com/en/support/chipsets/amd-socket-am4/x370"
license=('GPL2')
depends=('dkms')
makedepends=('linux-headers>=4.15')
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
        'linux-6.18.patch')
md5sums=('f5692d2ef952f8c903af90cdd9eb3ce6'
         '6f78c424353ae927e81bcbfec67afece'
         '461866e715a1fded49a3f7c043a173d7'
         'cac98de11cc5bd61fff72ff1c8cf363d'
         'bd1ef2b6bcefaec0abf7a832e937f01a'
         '916763c1eeb824f1c73e9dee717af05f'
         '848919b75f84a174a2d5d4025041aba0'
         'b2f5f1b930c14ccfd4fee84848638c6e'
         '59cac8e5011b4b623641de96dc712a68'
         '44d4591a3652ed8d6a5bb1ebed462312'
         '414bbbbe4884231ecb5107ba9bb3b891'
         'd50dfd065119fc19e9a8357c94395502'
         '15152035dc7b375b71707523e81f169d'
         '7709663aeeee89d2a8dc09a9ff16ba3f'
         '318eca1f828a62040469bb43dd731d94'
         'e09a474e5461f75cc99bdfe4ce1c0c96'
         '11cac54d40dc5b45b7a8b76544f68ce7'
         '849b9d9c89b27ea6c89ebaa14d8416a9')

prepare() {
    if [ ! -d ${_pkgbase}-${pkgver} ]; then
        mkdir ${_pkgbase}-${pkgver}
    fi

    cp driver_sdk/src/* ${_pkgbase}-${pkgver}
}

build() {
    cd ${_pkgbase}-${pkgver}

    local src
    for src in "${source[@]}"; do
        src="${src%%::*}"
        src="${src##*/}"
        src="${src%.zst}"
        [[ $src = *.patch ]] || continue
        echo "Applying patch $src..."
        patch -Np1 < "../$src"
    done

    make KVERS="${_kver}" all
}

package() {
    # Copy dkms.conf
    install -Dm644 dkms.conf "${pkgdir}"/usr/src/${_pkgbase}-${pkgver}/dkms.conf

    # Set name and version
    sed -e "s/@_PKGBASE@/${_pkgbase}/" \
            -e "s/@PKGVER@/${pkgver}/" \
            -i "${pkgdir}"/usr/src/${_pkgbase}-${pkgver}/dkms.conf

    cd ${_pkgbase}-${pkgver}

    install -Dm644 rcraid.ko "${pkgdir}"/usr/lib/modules/"${_kver}"/kernel/drivers/scsi/rcraid.ko

    make clean
    cp -r * "${pkgdir}"/usr/src/${_pkgbase}-${pkgver}/
}
