# Releases

Internal change log for the sourcekit.cc docs site. Not published to the website (lives outside `docs/`).

## 0.1.2 — 2026-05-31

Mini Tank Starter Kit (English + Chinese) — adjustments from a classroom trial run.

- **Step 4 reordered:** rear and front wheels moved to the end (now 4.5 and 4.6) so the chassis sits flat on the table during the screw-heavy electronics steps (OLED stand, 2S LiPo placement, RX mount). 4.1 includes a one-line note explaining the deferred wheel mounting.
- **In-class charging dropped:** removed the USB-hub-charging tip after Step 3, the USB-LiPo-charger tip after Experiment #4, and the "retrieve from charging" framing in 4.3. Charging time exceeds class time and the mass-charging cable chaos isn't worth it. The kit's USB chargers stay in the BOM — teachers handle charging between sessions.
- **New `## Pre-class Preparation` section** between *At a Glance* and Session 1: charge both batteries before class, confirm the right firmware on each board (with links to the MeshMass `05-OnDisconnect` lesson for RX4M4S and `20-MiniTank` lesson for TX6A4D), and pair the boards once (which also verifies the firmware). Includes a "pair one kit at a time" recommendation and links to the pairing sections on the RX4M4S and TX6A4D product pages.

## 0.1.1 — 2026-05-26

- Dev server binds to `0.0.0.0` (via `vite.server.host` in `.vitepress/config.js`) so it's reachable from other hosts on the LAN.
- Mini Tank Starter Kit: built out Session 1 (~3 hours) as a complete teacher's guide for ~10yo students. Five hands-on experiments in Step 1 (Simple Circuit, Bigger Battery, Speed Control by Timing) land electronics concepts; Step 2's parallel receiver/transmitter board tours culminate in Experiment #4 (Prove All the Electronics Work); Steps 3–4 assemble the controller and tank, closing with Experiment #5 (Why Tracks Matter); Step 5 plays. Session 1 Summary groups Electronics, Mechanics, Hardware, and Build. Session 2 (programming) marked WIP.
- Mini Tank Starter Kit: page structure reworked. Overview rewritten as a teacher-guide intro; product-shape info moved to "About the Kit" near the BOM. "Concept Coverage" replaced by a brief "At a Glance" preview. Beyond This Kit section added with five expansion branches. Discussion section with GitHub Discussions link. Removed blank chapters (Features, Drive System, Programming, Where to Buy, leftover Assembly stub).
- Mini Tank Starter Kit: Chinese version created (`docs/zh/MeshMass-Mini-Tank-Starter-Kit.md`) and added to the Chinese sidebar. ESL framing dropped since the Chinese-language audience reads in their native language.
- Replaced manual `Version: 1.0.0` lines with VitePress's built-in `lastUpdated` footer (enabled via `lastUpdated: true` in config). Applies to MeshMass-RX4M4S, MeshMass-TX6A4D, CircusGoggles, PiTray-clip, PiTray-mini, and all Chinese counterparts.
- Page outline: `outline: [2, 4]` in themeConfig so H4 headings (arc dividers, assembly sub-steps) appear in the right-side "On this page" panel.
- Cross-product links: TX6A4D and RX4M4S pages now list the Mini Tank Starter Kit as a Related Product.
- Mini Tank Starter Kit, Session 1 Step 1: tightened the closing. The three fragmented blocks (*Think About It! / The Problem / This is why we need MeshMass!*) are merged into a single *The Speed Problem* section that bridges directly into Step 2.
- Mini Tank Starter Kit, Session 1 Step 1: replaced the *How to Control It?* bullet list with an *Experiment: A Simple Circuit* section. The experiment introduces the **circuit** concept (1S battery + N20 motor + two wires), folds in a short-circuit safety caution, the **switch** concept (on/off via interrupting one wire), and the polarity reversal that was previously listed.

## 0.1.0 — 2026-05-26

- Dev server now binds to `0.0.0.0` so it's reachable from other hosts on the LAN.
- Removed unused `medium-zoom` Layout customization; image lightbox is handled by `vitepress-plugin-lightbox`.
- Removed dead `themeConfig.localeLinks` block from `.vitepress/config.js` (locale switcher is generated automatically from the `locales` config).
- Cleaned up commented scaffolding in `.vitepress/theme/index.js`.
- Fixed `MeshMass-Mini-Tank-Starter-Kit.md`: removed duplicate `## Programming` heading and moved tools/accessories out of the "3D Printed Parts" section.
- Updated `CLAUDE.md` to match repo reality (VitePress version, plugins in use, theme structure, product list).
- Deleted stale `MESHMASS-RX4M4S-MARKET-INSIGHTS.md` planning doc from the repo root.
