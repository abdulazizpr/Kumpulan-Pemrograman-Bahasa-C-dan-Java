-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: 24 Mei 2016 pada 05.47
-- Versi Server: 10.1.10-MariaDB
-- PHP Version: 7.0.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `gaji_pegawai`
--

-- --------------------------------------------------------

--
-- Struktur dari tabel `tgajipegawai`
--

CREATE TABLE `tgajipegawai` (
  `kode` varchar(20) NOT NULL,
  `nama` varchar(100) NOT NULL,
  `jenis_gaji` varchar(100) NOT NULL,
  `jumlah` decimal(15,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data untuk tabel `tgajipegawai`
--

INSERT INTO `tgajipegawai` (`kode`, `nama`, `jenis_gaji`, `jumlah`) VALUES
('1', 'Abdul Aziz Priatna', 'Lembur', '10000000.00'),
('2', 'Afrizal', 'Pokok', '200000.00'),
('3', 'Fadhil', 'Pokok', '400000.00'),
('4', 'Vini', 'Pokok', '2000000.00');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `tgajipegawai`
--
ALTER TABLE `tgajipegawai`
  ADD PRIMARY KEY (`kode`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
