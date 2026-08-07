# Releases

Internal change log for the sourcekit.cc docs site. Not published to the website (lives outside `docs/`).

## 0.2.0 — unreleased

MeshMass documentation rebuilt for the **raw protocol** firmware generation (upstream MeshMass 0.7.0). Boards now ship with `tx6ax` + `rx4mx`, so every code example on the site was describing a protocol customers no longer have. Applied to **both locales**.

**What changed in the firmware, for reference:** `getChannel()` returns an unsigned `0`-`255` raw reading (~`128` centred) instead of a signed `-127`-`127` value; the transmitter no longer centres, scales or mixes anything, and the receiver owns all of it. Separately, the `rx4m4s` / `rx4m3s1n` / `rx4m1s1n1a` firmware variants collapsed into one config-driven `rx4mx` scaffold selected by two `#define` switches. Sources: `chrc` (scaffolds) and `chrc-courses` (lessons).

- **`MeshMass-RX4M4S.md` — substantially rewritten.** The three-variant firmware table is replaced by the `rx4mx` config-flag model, now covering all **four** shapes including the sparse *audio-on / neo-off* case (servos SM0 and SM3, no 1 or 2) that the old table omitted entirely. Added a warning that `setServo()` indexes by silkscreen label rather than position. New *Default channel map* section with the stock channel assignment and the physical direction convention (raw `0` = right/down/anticlockwise). New *Centring a stick channel* section carrying the real `centered()` helper plus its mapping and deadzone tables.
- **RX4M4S code examples replaced by lesson links.** The ~250 lines of hand-written crane / excavator / lights / audio examples are gone; the page now carries the default program, an `onDisconnect()` failsafe example, and a short list naming a few vehicle lessons with a pointer to the course for the current set — the lesson list is still growing, so the page deliberately doesn't enumerate it. Notes that `*Demo` lessons exist to exercise the Neopixel and audio interfaces for hardware checks, not as vehicles to build from. The hand-written set had silently drifted wrong — `setMotor(0, getChannel(0))` reads a resting stick as full throttle under the raw protocol.
- **RX4M4S corrections:** `neoInit()` → `neoSetup()`; Neopixel strip limit 16 → 32 LEDs; added `mpStop()`, `mpLoop()` and `onDisconnect()` to the Quick Reference. OLED section corrected — channel values display unsigned, motor outputs signed, and headers claimed by a module show `MP3 ---` / `RGB` in place of a number.
- **`MeshMass-TX6A4D.md` — examples inverted.** The ten transmitter-side mixing / deadzone / exponential examples were teaching work that now belongs on the receiver; replaced with the stock pass-through program and an explanation of why shaping happens downstream. Added a note that `tx6ax` and `rx4mx` are firmware names on the existing hardware (not new products, and not interoperable with the legacy signed pair), and a warning that `setChannel()` is typed `int8_t` but carries a raw byte through unchanged.
- **`MeshMass-Introduction.md`:** channel description, the headline `150 + centered(4, 0) * 2 / 5` example, the firmware-variants bullet, and the *Math Comes Alive* list — which was built entirely on transmitter-side mixing that is now an anti-pattern.
- **`MeshMass-Mini-Tank-Starter-Kit.md`:** fixed the full-throttle bug in Session 2's first program, corrected the channel map (it claimed left stick = channel 0; the left stick vertical axis is channel 2), and repointed *Beyond This Kit* away from the dead `RX4M3S1N` / `RX4M1S1N1A` names. Session 2 remains a WIP stub.
- **`docs/code/` re-vendored.** Deleted the three obsolete RX variant headers (`RX4M4S/`, `RX4M3S1N/`, `RX4M1S1N1A/`) in favour of a single vendored `rx4mx/app.h`; `MeshMass-TX6A4D/app.h` is now the `tx6ax` header. These are transcluded into the API Reference via `<<< @/code/…`, so they should be re-copied from `chrc` rather than hand-edited.
- **The TX/RX asymmetry is now written down.** *Separation of Concerns* in the Introduction, and a tip on the TX6A4D page, explain why the split is deliberately uneven: a controller always looks the same, while a receiver gets bolted into a different machine every time — and the Neopixel and audio interfaces put still more of a build's behaviour on the receiver. Splitting logic across both ends would mean editing two programs on two boards to change one vehicle. TX6A4D is reframed as a **flash-once** board; the claim of a "comprehensive library of examples" for the transmitter is gone, since there is exactly one.
- **Platform naming adopted.** Hardware model **RX4M4S** runs the **RX4MX** firmware (*"RX4M4S Fusion Firmware"*); hardware model **TX6A4D** runs **TX6AX** (*"TX6A4D Raw Firmware"*). Pages now name the firmware where it matters instead of referring to scaffold directory names.
- **Lesson links point at the platform.** The RX4M4S lesson links, and the Mini Tank *Pre-class Preparation* links, now use real course keys (`RX4MX` = `12136090`, `TX6AX` = `12132971`) verified against `meshmass.y77.cc/api/courses`. Mini Tank's pre-flash lessons changed meaning with the architecture: the receiver now needs `02-MiniTank` (it holds the driving logic), and the transmitter takes `00-Default`.
- **New `## Upgrading the Firmware` section** in the Introduction: a plain recommendation to run TX6AX + RX4MX, a warning not to mix firmware generations across the link, a note that **pairing survives a re-flash** (held in EEPROM — no need to pair again), and a *Then / Now* porting table for anyone with code written against the earlier API.

- **Chinese pages mirrored.** All four zh MeshMass pages carry the same corrections, reusing the terminology already established in the `chrc-courses` lesson READMEs (原始无符号读数, 居中, 死区, 混控, 配置驱动) so the docs and the lessons read consistently for the same reader. `docs/code/zh/` re-vendored the same way: three variant headers replaced by one translated `rx4mx/app.h`, and the TX header's `getStick` updated (the only function that changed upstream). Cross-page CJK anchors verified against the built HTML.

**Known gaps after this release:** Only the `meshmass.y77.cc` course keys are verified — `meshmass.com` currently 301s to `dev.meshmass.com` and returns 403, so if the international instance uses different keys, the lesson links need a second set. The RX4M4S page still describes the audio module as *"sold separately, under development"*, which may be stale now that the firmware ships a complete MP3 API and four audio lessons.

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
